#pragma once

#include "Event.h"

class SentEvent: public Event
{
};

class SetSettingsEvent : public SentEvent
{

};

class GetSettingsEvent : public SentEvent
{
};

class SetGlobalSettingsEvent : public SentEvent
{
};

class GetGlobalSettingsEvent : public SentEvent 
{

};

class OpenUrlEvent : public SentEvent 
{

};

class LogMessageEvent : public SentEvent
{

};

class SetTitleEvent : public SentEvent
{

};

class SetImageEvent : public SentEvent
{

};

class ShowAlertEvent : public SentEvent
{

};

class ShowOkEvent : public SentEvent
{

};

class SetStateEvent : public SentEvent
{

};

class SwitchToProfileEvent : public SentEvent
{

};

class SendToPropertyInspectorEvent : public SentEvent
{

};

class SendToPluginEvent : public SentEvent
{

};

