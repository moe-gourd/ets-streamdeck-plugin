#include "pch.h"

#include "Connection.h"
#include "ConnectionManager.h"

Connection::Connection(ConnectionManager* connectionManager):connectionManager(connectionManager)
{
}

void Connection::sendMessage(std::string message)
{
	if (connectionManager != nullptr) {
		connectionManager->onMessage(message);
	}
}
