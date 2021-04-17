#include "pch.h"

#include "ConnectionManager.h"
#include "JSONUtils.h"

ConnectionManager::ConnectionManager(int argc, const char* const argv[])
{
	commandlineParser = new CommandlineParser(argc, argv);
}

void ConnectionManager::OnOpen(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
{
	DebugPrint("OnOpen");

	json jsonObject;
	jsonObject["event"] = commandlineParser->registerEvent();
	jsonObject["uuid"] = commandlineParser->pluginUUID();

	websocketpp::lib::error_code errorCode;
	webSocketClient.send(connectionHandle, jsonObject.dump(), websocketpp::frame::opcode::text, errorCode);
}


void ConnectionManager::OnFail(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
{
	std::string reason;

	if (nullptr == inClient)
	{
		WebsocketClient::connection_ptr connection = inClient->get_con_from_hdl(inConnectionHandler);
		if (connection != NULL)
		{
			reason = connection->get_ec().message();
		}
	}

	DebugPrint("Failed with reason: %s\n", reason.c_str());
}

void ConnectionManager::OnClose(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
{
	std::string reason;

	if (inClient != nullptr)
	{
		WebsocketClient::connection_ptr connection = inClient->get_con_from_hdl(inConnectionHandler);
		if (connection != NULL)
		{
			reason = connection->get_remote_close_reason();
		}
	}

	DebugPrint("Close with reason: %s\n", reason.c_str());
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
