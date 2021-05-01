#pragma once

#include "Event.h"

class SentEvent: public Event
{
public:
	SentEvent(std::string event);
	std::string dump();
};

class SetSettingsEvent : public SentEvent
{
public:
	SetSettingsEvent(std::string context);
	SetSettingsEvent(std::string context, json payload);

	void setPayload(json payload);

};

class GetSettingsEvent : public SentEvent
{
public:
	GetSettingsEvent(std::string context);
};

class SetGlobalSettingsEvent : public SentEvent
{
public:
	SetGlobalSettingsEvent(std::string context);
	SetGlobalSettingsEvent(std::string context, json payload);

	void setPayload(json payload);
};

class GetGlobalSettingsEvent : public SentEvent 
{
public:
	GetGlobalSettingsEvent(std::string context);
};

class OpenUrlEvent : public SentEvent 
{
public:
	OpenUrlEvent(std::string url);

};

class LogMessageEvent : public SentEvent
{
public:
	LogMessageEvent(std::string message);
};

class SetTitleEvent : public SentEvent
{
public:
	SetTitleEvent(std::string context);
	void setTitle(std::string& text, int target = 0, int state = 0);

};

class SetImageEvent : public SentEvent
{
public:
	SetImageEvent(std::string context);
	void setImage(std::string& image, int target = 0, int state = 0);

};

class ShowAlertEvent : public SentEvent
{
public:
	ShowAlertEvent(std::string context);
};

class ShowOkEvent : public SentEvent
{
public:
	ShowOkEvent(std::string context);

};

class SetStateEvent : public SentEvent
{
public:
	SetStateEvent(std::string context, int state = 0);
	void setState(int state);

};

class SwitchToProfileEvent : public SentEvent
{
public:
	SwitchToProfileEvent(std::string context, std::string device);
	SwitchToProfileEvent(std::string context, std::string device, std::string profile);
	void setProfile(std::string profile);

};

class SendToPropertyInspectorEventOut : public SentEvent
{
public:
	SendToPropertyInspectorEventOut(std::string action, std::string context);
	SendToPropertyInspectorEventOut(std::string action, std::string context, json payload);
	void setPayload(json payload);

};

class SendToPluginEventOut : public SentEvent
{
public:
	SendToPluginEventOut(std::string action, std::string context);
	SendToPluginEventOut(std::string action, std::string context, json payloadd);
	void setPayload(json payload);
};

