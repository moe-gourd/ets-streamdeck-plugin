#pragma once

#include <string>

class CommandlineParser
{
private:
	int mPort;
	std::string mPluginUUID;
	std::string mRegisterEvent;
	std::string mInfo;

	void parseArgumentList(int argc, const char* const argv[]);
	void parseArgument(int argumentId, const char* const argv[]);

public:
	CommandlineParser(int argc, const char* const argv[]);

	bool isValid();

	int port();
	std::string pluginUUID();
	std::string registerEvent();
	std::string info();
};

