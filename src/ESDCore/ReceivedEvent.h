#pragma once

#include "pch.h"
#include "JSONUtils.h"

class ReceivedEvent
{
public:
	static ReceivedEvent * fromMessage(std::string message);

private:
	std::string event;

protected:
	ReceivedEvent(std::string event, json jsonMessage);
};

class DidReceiveSettingsEvent : public ReceivedEvent
{
public:
	DidReceiveSettingsEvent(std::string event, json jsonMessage);
};

class DidReceiveGlobalSettingsEvent : public ReceivedEvent
{
public:
	DidReceiveGlobalSettingsEvent(std::string event, json jsonMessage);
};

class KeyDownEvent : public ReceivedEvent
{
public:
	KeyDownEvent(std::string event, json jsonMessage);
};

class KeyUpEvent : public ReceivedEvent
{
public:
	KeyUpEvent(std::string event, json jsonMessage);
};

class WillAppearEvent : public ReceivedEvent
{
public:
	WillAppearEvent(std::string event, json jsonMessage);
};

class WillDisappearEvent : public ReceivedEvent
{
public:
	WillDisappearEvent(std::string event, json jsonMessage);
};

class TitleParametersDidChangeEvent : public ReceivedEvent
{
public:
	TitleParametersDidChangeEvent(std::string event, json jsonMessage);
};

class DeviceDidConnectEvent : public ReceivedEvent
{
public:
	DeviceDidConnectEvent(std::string event, json jsonMessage);
};

class DeviceDidDisconnectEvent : public ReceivedEvent
{
public:
	DeviceDidDisconnectEvent(std::string event, json jsonMessage);
};

class ApplicationDidLaunchEvent : public ReceivedEvent
{
public:
	ApplicationDidLaunchEvent(std::string event, json jsonMessage);
};

class ApplicationDidTerminateEvent : public ReceivedEvent
{
public:
	ApplicationDidTerminateEvent(std::string event, json jsonMessage);
};

class SystemDidWakeUpEvent : public ReceivedEvent
{
public:
	SystemDidWakeUpEvent(std::string event, json jsonMessage);
};

class PropertyInspectorDidAppearEvent : public ReceivedEvent
{
public:
	PropertyInspectorDidAppearEvent(std::string event, json jsonMessage);
};

class PropertyInspectorDidDisappearEvent : public ReceivedEvent
{
public:
	PropertyInspectorDidDisappearEvent(std::string event, json jsonMessage);
};

class SendToPluginEvent : public ReceivedEvent
{
public:
	SendToPluginEvent(std::string event, json jsonMessage);
};

class SendToPropertyInspectorEvent : public ReceivedEvent
{
public:
	SendToPropertyInspectorEvent(std::string event, json jsonMessage);
};