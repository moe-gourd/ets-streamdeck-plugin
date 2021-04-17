#include "pch.h"
#include "WebsocketConnection.h"

WebsocketConnection::WebsocketConnection(std::string registerEvent, std::string pluginUUID)
{
}

void WebsocketConnection::OnOpen(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
{
}

void WebsocketConnection::OnFail(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
{
}

void WebsocketConnection::OnClose(WebsocketClient* inClient, websocketpp::connection_hdl inConnectionHandler)
{
}

void WebsocketConnection::OnMessage(websocketpp::connection_hdl, WebsocketClient::message_ptr inMsg)
{
}

void WebsocketConnection::connect(int port)
{
}
