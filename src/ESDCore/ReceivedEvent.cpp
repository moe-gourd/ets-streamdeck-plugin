#include "pch.h"
#include "ReceivedEvent.h"
#include "JSONUtils.h"

ReceivedEvent * ReceivedEvent::fromMessage(std::string message)
{
	json jsonMessage = json::parse(message);

	std::string event = JSONUtils::getStringByName(jsonMessage, "event");

	if ("didReceiveSettings" == event) {
		return new DidReceiveSettingsEvent(event, jsonMessage);
	}
	else if ("didReceiveGlobalSettings" == event) {
		return new DidReceiveGlobalSettingsEvent(event, jsonMessage);
	}
	else if ("keyDown" == event) {
		return new KeyDownEvent(event, jsonMessage);
	}
	else if ("keyUp" == event) {
		return new KeyUpEvent(event, jsonMessage);
	}
	else if ("willAppear" == event) {
		return new WillAppearEvent(event, jsonMessage);
	}
	else if ("willDisappear" == event) {
		return new WillDisappearEvent(event, jsonMessage);
	}
	else if ("titleParametersDidChange" == event) {
		return new TitleParametersDidChangeEvent(event, jsonMessage);
	}
	else if ("deviceDidConnect" == event) {
		return new DeviceDidConnectEvent(event, jsonMessage);
	}
	else if ("deviceDidDisconnect" == event) {
		return new DeviceDidDisconnectEvent(event, jsonMessage);
	}
	else if ("applicationDidLaunch" == event) {
		return new ApplicationDidLaunchEvent(event, jsonMessage);
	}
	else if ("applicationDidTerminate" == event) {
		return new ApplicationDidTerminateEvent(event, jsonMessage);
	}
	else if ("systemDidWakeUp" == event) {
		return new SystemDidWakeUpEvent(event, jsonMessage);
	}
	else if ("propertyInspectorDidAppear" == event) {
		return new PropertyInspectorDidAppearEvent(event, jsonMessage);
	}
	else if ("propertyInspectorDidDisappear" == event) {
		return new PropertyInspectorDidDisappearEvent(event, jsonMessage);
	}
	else if ("sendToPlugin" == event) {
		return new SendToPluginEvent(event, jsonMessage);
	}
	else if ("sendToPropertyInspector" == event) {
		return new SendToPropertyInspectorEvent(event, jsonMessage);
	}

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
