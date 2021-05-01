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
