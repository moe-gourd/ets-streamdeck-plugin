#include "pch.h"

#include "ConnectionManager.h"
#include "WebsocketConnection.h"
#include "ReceivedEvent.h"
#include "Plugin.h"

ConnectionManager::ConnectionManager()
{
}

void ConnectionManager::onMessage(std::string message)
{
	ReceivedEvent *event = ReceivedEvent::fromMessage(message);
	for (std::vector<Plugin*>::iterator it = pluginVector.begin(); it != pluginVector.end(); ++it) {
		event->eventAction(*it);
	}
	delete event;
}

void ConnectionManager::addPlugin(Plugin* plugin)
{
	plugin->setConnectionManager(this);
	pluginVector.push_back(plugin);
}