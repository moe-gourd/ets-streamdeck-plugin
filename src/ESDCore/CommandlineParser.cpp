#include "CommandlineParser.h"

CommandlineParser::CommandlineParser(int argc, const char* const argv[])
{
	mPort = 0;
}

bool CommandlineParser::isValid() {
	return false;
}

int CommandlineParser::port()
{
	return mPort;
}

std::string CommandlineParser::pluginUUID()
{
	return mPluginUUID;
}

std::string CommandlineParser::registerEvent()
{
	return mRegisterEvent;
}

std::string CommandlineParser::info()
{
	return mInfo;
}
