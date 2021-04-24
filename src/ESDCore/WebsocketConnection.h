#pragma once

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/common/thread.hpp>
#include <websocketpp/common/memory.hpp>

#include "Connection.h"

typedef websocketpp::config::asio_client::message_type::ptr message_ptr;
typedef websocketpp::client<websocketpp::config::asio_client> WebsocketClient;

class WebsocketConnection : public Connection
{
private:
	WebsocketClient webSocketClient;
	websocketpp::connection_hdl connectionHandle;

	// registration data
	std::string registerEvent;
	std::string pluginUUID;

	// Websocket callbacks
	void OnOpen(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler);
	void OnFail(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler);
	void OnClose(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler);
	void OnMessage(websocketpp::connection_hdl, WebsocketClient::message_ptr inMsg);

public:
	WebsocketConnection();

	virtual void run(std::string &registerEvent, std::string &pluginUUID, int port) override;
};

