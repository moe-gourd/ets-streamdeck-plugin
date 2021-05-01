#include "pch.h"
#include "Plugin.h"
#include "PluginAction.h"
#include "ConnectionManager.h"
#include "EventsSent.h"

void Plugin::addAction(std::string name, PluginAction* action)
{
	if (action != nullptr) {
		actionMap[name] = action;
		action->setPlugin(this);
	}

}

bool Plugin::isContextVisible(std::string& context)
{
	bool isVisible = false;
	visibleContextMutex.lock();
	isVisible = (visibleContextSet.find(context) != visibleContextSet.end());
	visibleContextMutex.unlock();
	return isVisible;
}

void Plugin::sendEvent(SentEvent& event)
{
	if (connectionManager != nullptr) {
		connectionManager->sendEvent(event);
	}
}

Plugin::Plugin() : connectionManager(nullptr)
{
}

void Plugin::setConnectionManager(const ConnectionManager* connectionManager)
{
	this->connectionManager = connectionManager;
}

PluginAction* Plugin::getActionFromString(std::string action)
{
	if (actionMap.find(action) == actionMap.end()) {
		DebugPrint("Action %s not listed", action);
		return PluginAction::getNullInstance();
	}

	PluginAction* pluginAction = actionMap[action];
	if (nullptr == pluginAction) {
		DebugPrint("Action %s not null", action);
		return PluginAction::getNullInstance();
	}

	return pluginAction;
}

void Plugin::didReceiveSettings(std::string& action, std::string& context, std::string& device, json& payload)
{
	PluginAction* pluginAction = getActionFromString(action);
	pluginAction->didReceiveSettings(context, device, payload);
}

void Plugin::didReceiveGlobalSettings(json& payload)
{
}

void Plugin::keyDown(std::string& action, std::string& context, std::string& device, json& payload)
{
	PluginAction* pluginAction = getActionFromString(action);
	pluginAction->keyDown(context, device, payload);
}

void Plugin::keyUp(std::string& action, std::string& context, std::string& device, json& payload)
{
	PluginAction* pluginAction = getActionFromString(action);
	pluginAction->keyUp(context, device, payload);
}

void Plugin::willAppear(std::string& action, std::string& context, std::string& device, json& payload)
{
	visibleContextMutex.lock();
	visibleContextSet.insert(context);
	visibleContextMutex.unlock();

	PluginAction* pluginAction = getActionFromString(action);
	pluginAction->willAppear(context, device, payload);
}

void Plugin::willDisappear(std::string& action, std::string& context, std::string& device, json& payload)
{
	visibleContextMutex.lock();
	visibleContextSet.erase(context);
	visibleContextMutex.unlock();

	PluginAction* pluginAction = getActionFromString(action);
	pluginAction->willDisappear(context, device, payload);
}

void Plugin::titleParametersDidChange(std::string& action, std::string& context, std::string& device, json& payload)
{
	PluginAction* pluginAction = getActionFromString(action);
	pluginAction->titleParametersDidChange(context, device, payload);
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
	PluginAction* pluginAction = getActionFromString(action);
	pluginAction->propertyInspectorDidAppear(context, device);
}

void Plugin::propertyInspectorDidDisappear(std::string& action, std::string& context, std::string& device)
{
	PluginAction* pluginAction = getActionFromString(action);
	pluginAction->propertyInspectorDidDisappear(context, device);
}

void Plugin::sendToPlugin(std::string& action, std::string& context, json& payload)
{
	PluginAction* pluginAction = getActionFromString(action);
	pluginAction->sendToPlugin(context, payload);
}

void Plugin::sendToPropertyInspector(std::string& action, std::string& context, json& payload)
{
	PluginAction* pluginAction = getActionFromString(action);
	pluginAction->sendToPropertyInspector(context, payload);
}
