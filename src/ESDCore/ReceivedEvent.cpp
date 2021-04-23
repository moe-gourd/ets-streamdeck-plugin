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

DidReceiveSettingsEvent::DidReceiveSettingsEvent(std::string event, json jsonMessage): ReceivedEvent(event, jsonMessage)
{
}

DidReceiveGlobalSettingsEvent::DidReceiveGlobalSettingsEvent(std::string event, json jsonMessage): ReceivedEvent(event, jsonMessage)
{
}

KeyDownEvent::KeyDownEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}


KeyUpEvent::KeyUpEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

WillAppearEvent::WillAppearEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

WillDisappearEvent::WillDisappearEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

TitleParametersDidChangeEvent::TitleParametersDidChangeEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

DeviceDidConnectEvent::DeviceDidConnectEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

DeviceDidDisconnectEvent::DeviceDidDisconnectEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

ApplicationDidLaunchEvent::ApplicationDidLaunchEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

ApplicationDidTerminateEvent::ApplicationDidTerminateEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

SystemDidWakeUpEvent::SystemDidWakeUpEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

PropertyInspectorDidAppearEvent::PropertyInspectorDidAppearEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

PropertyInspectorDidDisappearEvent::PropertyInspectorDidDisappearEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

SendToPluginEvent::SendToPluginEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

SendToPropertyInspectorEvent::SendToPropertyInspectorEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}
