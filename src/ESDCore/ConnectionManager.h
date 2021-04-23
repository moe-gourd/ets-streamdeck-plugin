#pragma once

#include <windows.h>
#include "CommandlineParser.h"

class WebsocketConnection;
class Plugin;

class ConnectionManager
{
private:
	WebsocketConnection* websocketConnection;
	std::vector<Plugin*> pluginVector;

public:
	ConnectionManager(int argc, const char* const argv[]);

	void OnMessage(std::string message);

	void addPlugin(Plugin* plugin);
};

