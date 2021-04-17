#pragma once

#include "CommandlineParser.h"

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/common/thread.hpp>
#include <websocketpp/common/memory.hpp>

typedef websocketpp::config::asio_client::message_type::ptr message_ptr;
typedef websocketpp::client<websocketpp::config::asio_client> WebsocketClient;

class ConnectionManager
{
private:
	CommandlineParser* commandlineParser;
	WebsocketClient webSocketClient;
	websocketpp::connection_hdl connectionHandle;

	// Websocket callbacks
	void OnOpen(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler);
	void OnFail(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler);
	void OnClose(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler);
	void OnMessage(websocketpp::connection_hdl, WebsocketClient::message_ptr inMsg);

public:
	ConnectionManager(int argc, const char* const argv[]);

	void connect();
};

