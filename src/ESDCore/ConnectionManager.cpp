#include "pch.h"

#include "ConnectionManager.h"
#include "WebsocketConnection.h"
#include "ReceivedEvent.h"

ConnectionManager::ConnectionManager(int argc, const char* const argv[])
{
	CommandlineParser commandlineParser(argc, argv);

	websocketConnection = new WebsocketConnection(this);
	websocketConnection->init(commandlineParser.registerEvent(), commandlineParser.pluginUUID());
	websocketConnection->connect(commandlineParser.port());
}

void ConnectionManager::OnMessage(std::string message)
{
	ReceivedEvent *event = ReceivedEvent::fromMessage(message);
	for (std::vector<Plugin*>::iterator it = pluginVector.begin(); it != pluginVector.end(); ++it) {
		event->eventAction(*it);
	}
	delete event;
}

void ConnectionManager::addPlugin(Plugin* plugin)
{
	pluginVector.push_back(plugin);
}
