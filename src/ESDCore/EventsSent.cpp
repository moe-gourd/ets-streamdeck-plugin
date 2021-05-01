#include "pch.h"
#include "EventsSent.h"

SentEvent::SentEvent(std::string event) : Event(event)
{
}

std::string SentEvent::dump()
{
	json jsonMessage;
	jsonMessage["event"] = event;

	if (!action.empty()) {
		jsonMessage["action"] = action;
	}

	if (!context.empty()) {
		jsonMessage["context"] = context;
	}

	if (!device.empty()) {
		jsonMessage["device"] = device;
	}

	if (!payload.empty()) {
		jsonMessage["payload"] = payload;
	}

	return jsonMessage.dump();
}

SetSettingsEvent::SetSettingsEvent(std::string context) : SentEvent(std::string("setSettings"))
{
	this->context = context;
}

SetSettingsEvent::SetSettingsEvent(std::string context, json payload) : SentEvent(std::string("setSettings"))
{
	this->context = context;
	setPayload(payload);
}

void SetSettingsEvent::setPayload(json payload)
{
	this->payload = payload;
}

GetSettingsEvent::GetSettingsEvent(std::string context) : SentEvent(std::string("getSettings"))
{
	this->context = context;
}

SetGlobalSettingsEvent::SetGlobalSettingsEvent(std::string context) : SentEvent(std::string("setGlobalSettings"))
{
	this->context = context;
}

SetGlobalSettingsEvent::SetGlobalSettingsEvent(std::string context, json payload) : SentEvent(std::string("setGlobalSettings"))
{
	this->context = context;
	setPayload(payload);
}

void SetGlobalSettingsEvent::setPayload(json payload)
{
	this->payload = payload;
}

GetGlobalSettingsEvent::GetGlobalSettingsEvent(std::string context) : SentEvent(std::string("getGlobalSettings"))
{
	this->context = context;
}

OpenUrlEvent::OpenUrlEvent(std::string url) : SentEvent(std::string("openUrl"))
{
	payload["url"] = url;
}

LogMessageEvent::LogMessageEvent(std::string message) : SentEvent(std::string("logMessage"))
{
	payload["message"] = message;
}

SetTitleEvent::SetTitleEvent(std::string context) : SentEvent(std::string("setTitle"))
{
	this->context = context;
}

void SetTitleEvent::setTitle(std::string& text, int target, int state)
{
	payload["title"] = text;
	payload["target"] = target;
	payload["state"] = state;
}

SetImageEvent::SetImageEvent(std::string context) : SentEvent(std::string("setImage"))
{
	this->context = context;
}

void SetImageEvent::setImage(std::string& image, int target, int state)
{
	payload["image"] = image;
	payload["target"] = target;
	payload["state"] = state;
}

ShowAlertEvent::ShowAlertEvent(std::string context) : SentEvent(std::string("showAlert"))
{
	this->context = context;
}

ShowOkEvent::ShowOkEvent(std::string context) : SentEvent(std::string("showOK"))
{
	this->context = context;
}

SetStateEvent::SetStateEvent(std::string context, int state) : SentEvent(std::string("setState"))
{
	this->setState(state);
}

void SetStateEvent::setState(int state)
{
	payload["state"] = state;
}

SwitchToProfileEvent::SwitchToProfileEvent(std::string context, std::string device) : SentEvent(std::string("switchToProfile"))
{
	this->device = device;
}

SwitchToProfileEvent::SwitchToProfileEvent(std::string context, std::string device, std::string profile) : SentEvent(std::string("switchToProfile"))
{
	this->device = device;
	setProfile(profile);
}

void SwitchToProfileEvent::setProfile(std::string profile)
{
	payload["profile"] = profile;
}

SendToPropertyInspectorEventOut::SendToPropertyInspectorEventOut(std::string action, std::string context) :SentEvent(std::string("sendToPropertyInspector"))
{
	this->action = action;
	this->context = context;
}

SendToPropertyInspectorEventOut::SendToPropertyInspectorEventOut(std::string action, std::string context, json payload) :SentEvent(std::string("sendToPropertyInspector"))
{
	this->action = action;
	this->context = context;
	setPayload(payload);
}

void SendToPropertyInspectorEventOut::setPayload(json payload)
{
	this->payload = payload;
}

SendToPluginEventOut::SendToPluginEventOut(std::string action, std::string context) : SentEvent(std::string("sendToPluginEvent"))
{
	this->action = action;
	this->context = context;
}

SendToPluginEventOut::SendToPluginEventOut(std::string action, std::string context, json payload) : SentEvent(std::string("sendToPluginEvent"))
{
	this->action = action;
	this->context = context;
	setPayload(payload);
}

void SendToPluginEventOut::setPayload(json payload)
{
	this->payload = payload;
}
