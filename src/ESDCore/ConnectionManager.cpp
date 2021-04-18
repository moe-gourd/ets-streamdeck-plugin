#include "pch.h"

#include "ConnectionManager.h"
#include "WebsocketConnection.h"
#include "JSONUtils.h"

ConnectionManager::ConnectionManager(int argc, const char* const argv[])
{
	CommandlineParser commandlineParser(argc, argv);

	websocketConnection = new WebsocketConnection(this);
	websocketConnection->init(commandlineParser.registerEvent(), commandlineParser.pluginUUID());
	websocketConnection->connect(commandlineParser.port());
}

void ConnectionManager::OnMessage(std::string message)
{
	try {
		json jsonMessage = json::parse(message);

		std::string event = JSONUtils::getStringByName(jsonMessage, "event");
		std::string context = JSONUtils::getStringByName(jsonMessage, "context");
		std::string action = JSONUtils::getStringByName(jsonMessage, "action");
		std::string deviceId = JSONUtils::getStringByName(jsonMessage, "device");

		json payload;
		JSONUtils::getObjectByName(jsonMessage, "payload", payload);

	}
	catch (...) {
		DebugPrint("Error during Message parsing\n");
	}
}
