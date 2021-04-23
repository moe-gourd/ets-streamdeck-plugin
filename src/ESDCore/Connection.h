#pragma once

class ConnectionManager;

class Connection
{
private:
	ConnectionManager* connectionManager;

public:
	static Connection* createWebsocketConnection(ConnectionManager* connectionManager);

	Connection(ConnectionManager* connectionManager);

	void sendMessage(std::string message);
};

