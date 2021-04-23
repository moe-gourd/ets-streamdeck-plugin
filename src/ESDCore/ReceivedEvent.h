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