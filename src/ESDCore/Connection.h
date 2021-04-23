#pragma once

class ConnectionManager;

class Connection
{
private:
	ConnectionManager* connectionManager;

public:
	Connection(ConnectionManager* connectionManager);

};

