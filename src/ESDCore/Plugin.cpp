#include "pch.h"
#include "Plugin.h"
#include "ConnectionManager.h"

void Plugin::addAction(std::string name, PluginAction* action)
{
	actionMap[name] = action;
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

void Plugin::sendToPlugin(std::string& action, std::string& context, json& payload)
{
}

void Plugin::sendToPropertyInspector(std::string& action, std::string& context, json& payload)
{
}

void Plugin::propertyInspectorDidDisappear(std::string& action, std::string& context, std::string& device)
{
}
