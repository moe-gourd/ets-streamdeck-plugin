#pragma once

class ConnectionManager;

class Connection
{
private:
	ConnectionManager* connectionManager;

public:
	static Connection* createWebsocketConnection();

	Connection();
	void setConnectionManager(ConnectionManager* connectionManager);
	virtual void run(std::string& registerEvent, std::string& pluginUUID, int port) = 0;
	virtual void sendMessage(std::string& message) = 0;

protected:
	void onMessage(std::string message);
	
};

