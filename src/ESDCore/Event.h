#pragma once

#include "JSONUtils.h"

class Event
{
protected:
	std::string event;
	std::string action;
	std::string context;
	std::string device;

	// json deviceInfo; // deviceDidConnect only
	json payload;

	Event(std::string& event);

private:
	Event();
};

