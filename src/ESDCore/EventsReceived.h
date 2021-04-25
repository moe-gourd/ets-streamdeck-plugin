#pragma once

#include "pch.h"
#include "JSONUtils.h"

class Plugin;

class ReceivedEvent
{
public:
	static ReceivedEvent * fromMessage(std::string message);

	virtual void eventAction(Plugin* plugin);

protected:
	std::string event;
	std::string action;
	std::string context;
	std::string device;
	
	// json deviceInfo; // deviceDidConnect only
	json payload;

	ReceivedEvent(std::string event, json jsonMessage);
};

class DidReceiveSettingsEvent : public ReceivedEvent
{
public:
	DidReceiveSettingsEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class DidReceiveGlobalSettingsEvent : public ReceivedEvent
{
public:
	DidReceiveGlobalSettingsEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class KeyDownEvent : public ReceivedEvent
{
public:
	KeyDownEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class KeyUpEvent : public ReceivedEvent
{
public:
	KeyUpEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class WillAppearEvent : public ReceivedEvent
{
public:
	WillAppearEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class WillDisappearEvent : public ReceivedEvent
{
public:
	WillDisappearEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class TitleParametersDidChangeEvent : public ReceivedEvent
{
public:
	TitleParametersDidChangeEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class DeviceDidConnectEvent : public ReceivedEvent
{
protected:
	json deviceInfo;
public:
	DeviceDidConnectEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class DeviceDidDisconnectEvent : public ReceivedEvent
{
public:
	DeviceDidDisconnectEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class ApplicationDidLaunchEvent : public ReceivedEvent
{
public:
	ApplicationDidLaunchEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class ApplicationDidTerminateEvent : public ReceivedEvent
{
public:
	ApplicationDidTerminateEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class SystemDidWakeUpEvent : public ReceivedEvent
{
public:
	SystemDidWakeUpEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class PropertyInspectorDidAppearEvent : public ReceivedEvent
{
public:
	PropertyInspectorDidAppearEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class PropertyInspectorDidDisappearEvent : public ReceivedEvent
{
public:
	PropertyInspectorDidDisappearEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class SendToPluginEvent : public ReceivedEvent
{
public:
	SendToPluginEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};

class SendToPropertyInspectorEvent : public ReceivedEvent
{
public:
	SendToPropertyInspectorEvent(std::string event, json jsonMessage);
	virtual void eventAction(Plugin* plugin) override;
};