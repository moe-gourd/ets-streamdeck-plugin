#include "pch.h"

#include "ConnectionManager.h"
#include "WebsocketConnection.h"
#include "JSONUtils.h"

ConnectionManager::ConnectionManager(int argc, const char* const argv[])
{
	CommandlineParser commandlineParser(argc, argv);

	websocketConnection = new WebsocketConnection(commandlineParser.registerEvent(), commandlineParser.pluginUUID());
	websocketConnection->connect(commandlineParser.port());
}