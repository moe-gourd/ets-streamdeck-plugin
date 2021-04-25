#include "pch.h"
#include "EventsReceived.h"
#include "JSONUtils.h"
#include "Plugin.h"

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
	context = JSONUtils::getStringByName(jsonMessage, "context");
	action = JSONUtils::getStringByName(jsonMessage, "action");
	device = JSONUtils::getStringByName(jsonMessage, "device");

	JSONUtils::getObjectByName(jsonMessage, "payload", payload);
}

void ReceivedEvent::eventAction(Plugin* plugin)
{
	DebugPrint("eventAction triggered for unknown event %s", event);
}

DidReceiveSettingsEvent::DidReceiveSettingsEvent(std::string event, json jsonMessage): ReceivedEvent(event, jsonMessage)
{
}

void DidReceiveSettingsEvent::eventAction(Plugin* plugin)
{
	plugin->didReceiveSettings(action, context, device, payload);
}

DidReceiveGlobalSettingsEvent::DidReceiveGlobalSettingsEvent(std::string event, json jsonMessage): ReceivedEvent(event, jsonMessage)
{
}

void DidReceiveGlobalSettingsEvent::eventAction(Plugin* plugin)
{
	plugin->didReceiveGlobalSettings(payload);
}

KeyDownEvent::KeyDownEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void KeyDownEvent::eventAction(Plugin* plugin)
{
	plugin->keyDown(action, context, device, payload);
}


KeyUpEvent::KeyUpEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void KeyUpEvent::eventAction(Plugin* plugin)
{
	plugin->keyUp(action, context, device, payload);
}

WillAppearEvent::WillAppearEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void WillAppearEvent::eventAction(Plugin* plugin)
{
	plugin->willAppear(action, context, device, payload);
}

WillDisappearEvent::WillDisappearEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void WillDisappearEvent::eventAction(Plugin* plugin)
{
	plugin->willDisappear(action, context, device, payload);
}

TitleParametersDidChangeEvent::TitleParametersDidChangeEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void TitleParametersDidChangeEvent::eventAction(Plugin* plugin)
{
	plugin->titleParametersDidChange(action, context, device, payload);
}

DeviceDidConnectEvent::DeviceDidConnectEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
	JSONUtils::getObjectByName(jsonMessage, "deviceInfo", deviceInfo);
}

void DeviceDidConnectEvent::eventAction(Plugin* plugin)
{
	plugin->deviceDidConnect(device, deviceInfo);
}

DeviceDidDisconnectEvent::DeviceDidDisconnectEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void DeviceDidDisconnectEvent::eventAction(Plugin* plugin)
{
	plugin->deviceDidDisconnect(device);
}

ApplicationDidLaunchEvent::ApplicationDidLaunchEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void ApplicationDidLaunchEvent::eventAction(Plugin* plugin)
{
	plugin->applicationDidLaunch(payload);
}

ApplicationDidTerminateEvent::ApplicationDidTerminateEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void ApplicationDidTerminateEvent::eventAction(Plugin* plugin)
{
	plugin->applicationDidTerminate(payload);
}

SystemDidWakeUpEvent::SystemDidWakeUpEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void SystemDidWakeUpEvent::eventAction(Plugin* plugin)
{
	plugin->systemDidWakeUp();
}

PropertyInspectorDidAppearEvent::PropertyInspectorDidAppearEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void PropertyInspectorDidAppearEvent::eventAction(Plugin* plugin)
{
	plugin->propertyInspectorDidAppear(action, context, device);
}

PropertyInspectorDidDisappearEvent::PropertyInspectorDidDisappearEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void PropertyInspectorDidDisappearEvent::eventAction(Plugin* plugin)
{
	plugin->propertyInspectorDidDisappear(action, context, device);
}

SendToPluginEvent::SendToPluginEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void SendToPluginEvent::eventAction(Plugin* plugin)
{
	plugin->sendToPlugin(action, context, payload);
}

SendToPropertyInspectorEvent::SendToPropertyInspectorEvent(std::string event, json jsonMessage) : ReceivedEvent(event, jsonMessage)
{
}

void SendToPropertyInspectorEvent::eventAction(Plugin* plugin)
{
	plugin->sendToPropertyInspector(action, context, payload);
}
