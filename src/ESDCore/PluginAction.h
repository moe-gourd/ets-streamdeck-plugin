#pragma once

#include "JSONUtils.h"

class PluginAction
{
public:
	virtual void didReceiveSettings(std::string& context, std::string& device, json& payload);
	virtual void keyDown(std::string& context, std::string& device, json& payload);
	virtual void keyUp(std::string& context, std::string& device, json& payload);
	virtual void willAppear(std::string& context, std::string& device, json& payload);
	virtual void willDisappear(std::string& context, std::string& device, json& payload);
	virtual void titleParametersDidChange(std::string& context, std::string& device, json& payload);
	virtual void propertyInspectorDidAppear(std::string& context, std::string& device);
	virtual void propertyInspectorDidDisappear(std::string& context, std::string& device);
	virtual void sendToPlugin(std::string& context, json& payload);
	virtual void sendToPropertyInspector(std::string& context, json& payload);
};

