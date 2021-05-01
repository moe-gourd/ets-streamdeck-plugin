#include "pch.h"

#include "Connection.h"
#include "ConnectionManager.h"
#include "WebsocketConnection.h"

Connection* Connection::createWebsocketConnection()
{
	return new WebsocketConnection();
}

Connection::Connection():connectionManager(nullptr)
{
}

void Connection::setConnectionManager(ConnectionManager* connectionManager) {
	this->connectionManager = connectionManager;
}

void Connection::onMessage(std::string message)
{
	if (connectionManager != nullptr) {
		connectionManager->onMessage(message);
	}
}
