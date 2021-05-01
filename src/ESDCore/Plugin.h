#pragma once

#include <mutex>
#include <set>

#include "JSONUtils.h"

class ConnectionManager;
class PluginAction;
class SentEvent;

class Plugin
{
protected:
	const ConnectionManager* connectionManager;

	std::unordered_map<std::string, PluginAction*> actionMap;

	void addAction(std::string name, PluginAction* action);
	PluginAction* getActionFromString(std::string action);

	// TODO encapsulate?
	std::mutex visibleContextMutex;
	std::set<std::string> visibleContextSet;

	bool isContextVisible(std::string& context);
	void sendEvent(SentEvent& event);

public:
	Plugin();

	void setConnectionManager(const ConnectionManager* connectionManager);

	virtual void didReceiveSettings(std::string& action, std::string& context, std::string& device, json& payload);
	virtual void didReceiveGlobalSettings(json& payload);
	virtual void keyDown(std::string& action, std::string& context, std::string& device, json& payload);
	virtual void keyUp(std::string& action, std::string& context, std::string& device, json& payload);
	virtual void willAppear(std::string& action, std::string& context, std::string& device, json& payload);
	virtual void willDisappear(std::string& action, std::string& context, std::string& device, json& payload);
	virtual void titleParametersDidChange(std::string& action, std::string& context, std::string& device, json& payload);
	virtual void deviceDidConnect(std::string& device, json& deviceInfo);
	virtual void deviceDidDisconnect(std::string& device);
	virtual void applicationDidLaunch(json& payload);
	virtual void applicationDidTerminate(json& payload);
	virtual void systemDidWakeUp();
	virtual void propertyInspectorDidAppear(std::string& action, std::string& context, std::string& device);
	virtual void propertyInspectorDidDisappear(std::string& action, std::string& context, std::string& device);
	virtual void sendToPlugin(std::string& action, std::string& context, json& payload);
	virtual void sendToPropertyInspector(std::string& action, std::string& context, json& payload);
};

