#pragma once

#include <vector>
#include <string>

class Connection;
class Plugin;
class SentEvent;

class ConnectionManager
{
private:
	Connection* connection;
	std::vector<Plugin*> pluginVector;

public:
	ConnectionManager();

	void setConnection(Connection* connection);
	void onMessage(std::string message);
	void addPlugin(Plugin* plugin);
	void sendEvent(SentEvent& event);
};

