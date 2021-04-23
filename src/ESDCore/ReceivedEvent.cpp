#include "pch.h"
#include "ReceivedEvent.h"
#include "JSONUtils.h"

ReceivedEvent * ReceivedEvent::fromMessage(std::string message)
{
	json jsonMessage = json::parse(message);

	std::string event = JSONUtils::getStringByName(jsonMessage, "event");

	// define subtype by event

	return new ReceivedEvent(event, jsonMessage);
}

ReceivedEvent::ReceivedEvent(std::string event, json jsonMessage): event(event)
{
	std::string context = JSONUtils::getStringByName(jsonMessage, "context");
	std::string action = JSONUtils::getStringByName(jsonMessage, "action");
	std::string deviceId = JSONUtils::getStringByName(jsonMessage, "device");

	json payload;
	JSONUtils::getObjectByName(jsonMessage, "payload", payload);
}