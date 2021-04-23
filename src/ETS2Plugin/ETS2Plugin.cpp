//==============================================================================


#include "ConnectionManager.h"
#include "Connection.h"
#include "CommandlineParser.h"
#include "TestPlugin.h"


int main(int argc, const char* const argv[])
{
    ConnectionManager *connectionManager = new ConnectionManager();
    Connection *connection = Connection::createWebsocketConnection(connectionManager);
    connectionManager->setConnection(connection);

    Plugin* plugin = new Plugin();
    connectionManager->addPlugin(plugin);

    CommandlineParser commandlineparser(argc, argv);
    std::string registerEvent = commandlineparser.registerEvent();
    std::string pluginUUID = commandlineparser.pluginUUID();
    int port = commandlineparser.port();

    connection->run(registerEvent, pluginUUID, port);
}
