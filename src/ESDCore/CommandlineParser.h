#pragma once

#include <string>

class CommandlineParser
{
private:
	int mPort;
	std::string mPluginUUID;
	std::string mRegisterEvent;
	std::string mInfo;

public:
	CommandlineParser(int argc, const char* const argv[]);

	bool isValid();

	int port();
	std::string pluginUUID();
	std::string registerEvent();
	std::string info();
};

