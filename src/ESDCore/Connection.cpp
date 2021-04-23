#include "pch.h"

#include "Connection.h"
#include "ConnectionManager.h"
#include "WebsocketConnection.h"

Connection* Connection::createWebsocketConnection(ConnectionManager* connectionManager)
{
	return new WebsocketConnection(connectionManager);
}

Connection::Connection(ConnectionManager* connectionManager):connectionManager(connectionManager)
{
}

void Connection::sendMessage(std::string message)
{
	if (connectionManager != nullptr) {
		connectionManager->onMessage(message);
	}
}
