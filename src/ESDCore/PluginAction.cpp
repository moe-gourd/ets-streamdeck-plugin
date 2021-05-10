#include "pch.h"

#include "PluginAction.h"
#include "Plugin.h"

PluginAction* PluginAction::nullInstance = nullptr;

PluginAction* PluginAction::getNullInstance()
{
	if (nullptr == nullInstance) {
		nullInstance = new PluginAction();
	}
	return nullInstance;
}

void PluginAction::didReceiveSettings(std::string& context, std::string& device, json& payload)
{
}

void PluginAction::setPlugin(Plugin* plugin)
{
	this->parentPlugin = plugin;
}

void PluginAction::keyDown(std::string& context, std::string& device, json& payload)
{
}

void PluginAction::keyUp(std::string& context, std::string& device, json& payload)
{
}

void PluginAction::willAppear(std::string& context, std::string& device, json& payload)
{
}

void PluginAction::willDisappear(std::string& context, std::string& device, json& payload)
{
}

void PluginAction::titleParametersDidChange(std::string& context, std::string& device, json& payload)
{
}

void PluginAction::propertyInspectorDidAppear(std::string& context, std::string& device)
{
}

void PluginAction::propertyInspectorDidDisappear(std::string& context, std::string& device)
{
}

void PluginAction::sendToPlugin(std::string& context, json& payload)
{
}

void PluginAction::sendToPropertyInspector(std::string& context, json& payload)
{
}

void PluginAction::onTimer(std::string& context)
{
}
