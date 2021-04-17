#include "pch.h"
#include "ConnectionManager.h"

ConnectionManager::ConnectionManager(int argc, const char* const argv[])
{
	commandlineParser = new CommandlineParser(argc, argv);
}

void ConnectionManager::OnOpen(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
{}

void ConnectionManager::OnFail(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
{
}

void ConnectionManager::OnClose(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
{
}

void ConnectionManager::OnMessage(websocketpp::connection_hdl, WebsocketClient::message_ptr inMsg)
{
}

void ConnectionManager::connect()
{
	try
	{
		// Create the endpoint
		webSocketClient.clear_access_channels(websocketpp::log::alevel::all);
		webSocketClient.clear_error_channels(websocketpp::log::elevel::all);

		// Initialize ASIO
		webSocketClient.init_asio();

		// Register our message handler
		webSocketClient.set_open_handler(websocketpp::lib::bind(&ConnectionManager::OnOpen, this, &webSocketClient, websocketpp::lib::placeholders::_1));
		webSocketClient.set_fail_handler(websocketpp::lib::bind(&ConnectionManager::OnFail, this, &webSocketClient, websocketpp::lib::placeholders::_1));
		webSocketClient.set_close_handler(websocketpp::lib::bind(&ConnectionManager::OnClose, this, &webSocketClient, websocketpp::lib::placeholders::_1));
		webSocketClient.set_message_handler(websocketpp::lib::bind(&ConnectionManager::OnMessage, this, websocketpp::lib::placeholders::_1, websocketpp::lib::placeholders::_2));

		websocketpp::lib::error_code ec;
		std::string uri = "ws://127.0.0.1:" + std::to_string(commandlineParser->port());
		WebsocketClient::connection_ptr connection = webSocketClient.get_connection(uri, ec);
		if (ec)
		{
			// DebugPrint("Connect initialization error: %s\n", ec.message().c_str());
			return;
		}

		connectionHandle = connection->get_handle();

		// Note that connect here only requests a connection. No network messages are
		// exchanged until the event loop starts running in the next line.
		webSocketClient.connect(connection);

		// Start the ASIO io_service run loop
		// this will cause a single connection to be made to the server. mWebsocket.run()
		// will exit when this connection is closed.
		webSocketClient.run();
	}
	catch (websocketpp::exception const&)
	{
		// TODO
	}
}
