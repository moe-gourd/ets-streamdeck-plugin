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

	virtual void run(std::string &registerEvent, std::string &pluginUUID, int port) = 0;
};

