#pragma once

#include "CommandlineParser.h"

class WebsocketConnection;

class ConnectionManager
{
private:
	WebsocketConnection* websocketConnection;
public:
	ConnectionManager(int argc, const char* const argv[]);
};

