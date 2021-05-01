#include "pch.h"
#include "WebsocketConnection.h"
#include "ConnectionManager.h"
#include "JSONUtils.h"

WebsocketConnection::WebsocketConnection()
{
}

void WebsocketConnection::OnOpen(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
{
	DebugPrint("OnOpen");

	json jsonObject;
	jsonObject["event"] = registerEvent;
	jsonObject["uuid"] = pluginUUID;

	websocketpp::lib::error_code errorCode;
	webSocketClient.send(connectionHandle, jsonObject.dump(), websocketpp::frame::opcode::text, errorCode);
}

void WebsocketConnection::OnFail(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
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

void WebsocketConnection::OnClose(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
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

void WebsocketConnection::OnMessage(websocketpp::connection_hdl, WebsocketClient::message_ptr inMsg)
{
	if (inMsg != NULL && inMsg->get_opcode() == websocketpp::frame::opcode::text)
	{
		std::string message = inMsg->get_payload();
		DebugPrint("OnMessage: %s\n", message.c_str());

		Connection::onMessage(message);
	}
}

void WebsocketConnection::run(std::string &registerEvent, std::string &pluginUUID, int port)
{
	this->registerEvent = registerEvent;
	this->pluginUUID = pluginUUID;

	try
	{
		// Create the endpoint
		webSocketClient.clear_access_channels(websocketpp::log::alevel::all);
		webSocketClient.clear_error_channels(websocketpp::log::elevel::all);

		// Initialize ASIO
		webSocketClient.init_asio();

		// Register our message handler
		webSocketClient.set_open_handler(websocketpp::lib::bind(&WebsocketConnection::OnOpen, this, &webSocketClient, websocketpp::lib::placeholders::_1));
		webSocketClient.set_fail_handler(websocketpp::lib::bind(&WebsocketConnection::OnFail, this, &webSocketClient, websocketpp::lib::placeholders::_1));
		webSocketClient.set_close_handler(websocketpp::lib::bind(&WebsocketConnection::OnClose, this, &webSocketClient, websocketpp::lib::placeholders::_1));
		webSocketClient.set_message_handler(websocketpp::lib::bind(&WebsocketConnection::OnMessage, this, websocketpp::lib::placeholders::_1, websocketpp::lib::placeholders::_2));

		websocketpp::lib::error_code ec;
		std::string uri = "ws://127.0.0.1:" + std::to_string(port);
		WebsocketClient::connection_ptr connection = webSocketClient.get_connection(uri, ec);
		if (ec)
		{
			DebugPrint("Connect initialization error: %s\n", ec.message().c_str());
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
	catch (websocketpp::exception const& e)
	{
		const char* reason = e.what();
		DebugPrint("Websocket threw an exception: %s\n", reason);
	}
}

void WebsocketConnection::sendMessage(std::string& message)
{
	websocketpp::lib::error_code errorCode;
	webSocketClient.send(connectionHandle, message, websocketpp::frame::opcode::text, errorCode);
}
