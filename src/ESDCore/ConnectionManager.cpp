#include "pch.h"

#include "ConnectionManager.h"
#include "Connection.h"
#include "EventsReceived.h"
#include "Plugin.h"

ConnectionManager::ConnectionManager() : connection(nullptr)
{
}

void ConnectionManager::setConnection(Connection* connection)
{
	this->connection = connection;
	if (connection != nullptr) {
		connection->setConnectionManager(this);
	}
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