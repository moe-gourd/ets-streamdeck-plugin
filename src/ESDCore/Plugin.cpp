#include "pch.h"
#include "Plugin.h"
#include "PluginAction.h"
#include "ConnectionManager.h"
#include "EventsSent.h"

void Plugin::sendEvent(SentEvent& event)
{
	if (connectionManager != nullptr) {
		connectionManager->sendEvent(event);
	}
}

void Plugin::startTimer(int interval)
{
	callbackTimer.start(1000, [this]()
		{
			this->onTimer();
		}
	);
}

void Plugin::stopTimer()
{
	callbackTimer.stop();
}

void Plugin::onTimer()
{
}

Plugin::Plugin() : connectionManager(nullptr)
{
}

void Plugin::setConnectionManager(const ConnectionManager* connectionManager)
{
	this->connectionManager = connectionManager;
}

void Plugin::didReceiveSettings(std::string& action, std::string& context, std::string& device, json& payload)
{
}

void Plugin::didReceiveGlobalSettings(json& payload)
{
}

void Plugin::keyDown(std::string& action, std::string& context, std::string& device, json& payload)
{
}

void Plugin::keyUp(std::string& action, std::string& context, std::string& device, json& payload)
{
}

void Plugin::willAppear(std::string& action, std::string& context, std::string& device, json& payload)
{
}

void Plugin::willDisappear(std::string& action, std::string& context, std::string& device, json& payload)
{
}

void Plugin::titleParametersDidChange(std::string& action, std::string& context, std::string& device, json& payload)
{
}

void Plugin::deviceDidConnect(std::string& device, json& deviceInfo)
{
}

void Plugin::deviceDidDisconnect(std::string& device)
{
}

void Plugin::applicationDidLaunch(json& payload)
{
}

void Plugin::applicationDidTerminate(json& payload)
{
}

void Plugin::systemDidWakeUp()
{
}

void Plugin::propertyInspectorDidAppear(std::string& action, std::string& context, std::string& device)
{
}

void Plugin::propertyInspectorDidDisappear(std::string& action, std::string& context, std::string& device)
{
}

void Plugin::sendToPlugin(std::string& action, std::string& context, json& payload)
{
}

void Plugin::sendToPropertyInspector(std::string& action, std::string& context, json& payload)
{
}

bool ContextPlugin::isContextVisible(std::string& context)
{
	bool isVisible = false;
	visibleContextMutex.lock();
	isVisible = (visibleContextSet.find(context) != visibleContextSet.end());
	visibleContextMutex.unlock();
	return isVisible;
}

void ContextPlugin::willAppear(std::string& action, std::string& context, std::string& device, json& payload)
{
	visibleContextMutex.lock();
	visibleContextSet.insert(context);
	visibleContextMutex.unlock();
}

void ContextPlugin::willDisappear(std::string& action, std::string& context, std::string& device, json& payload)
{
	visibleContextMutex.lock();
	visibleContextSet.erase(context);
	visibleContextMutex.unlock();
}

bool ContextActionPlugin::isContextVisible(std::string& context)
{
	bool isVisible = false;
	visibleContextMutex.lock();
	isVisible = (visibleContextMap.find(context) != visibleContextMap.end());
	visibleContextMutex.unlock();
	return isVisible;
}

PluginAction* ContextActionPlugin::getPluginAction(std::string& action)
{
	return PluginAction::getNullInstance();
}

void ContextActionPlugin::willAppear(std::string& action, std::string& context, std::string& device, json& payload)
{
	PluginAction* pluginAction = getPluginAction(action);
	if (pluginAction != nullptr) {
		pluginAction->willAppear(context, device, payload);
	}

	visibleContextMutex.lock();
	visibleContextMap[context] = pluginAction;
	visibleContextMutex.unlock();
}

void ContextActionPlugin::willDisappear(std::string& action, std::string& context, std::string& device, json& payload)
{
	PluginAction* pluginAction;

	visibleContextMutex.lock();
	pluginAction = visibleContextMap[context];
	visibleContextMap[context] = nullptr;
	visibleContextMap.erase(context);
	visibleContextMutex.unlock();

	if (pluginAction != nullptr) {
		pluginAction->willDisappear(context, device, payload);
	}
	delete pluginAction;
}
