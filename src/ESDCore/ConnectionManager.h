#pragma once

#include <windows.h>
#include <vector>
#include "CommandlineParser.h"

class WebsocketConnection;
class Plugin;

class ConnectionManager
{
private:
	WebsocketConnection* websocketConnection;
	std::vector<Plugin*> pluginVector;

public:
	ConnectionManager();

	void onMessage(std::string message);
	void addPlugin(Plugin* plugin);
};

