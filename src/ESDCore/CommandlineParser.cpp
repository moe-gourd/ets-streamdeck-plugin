#include "CommandlineParser.h"

CommandlineParser::CommandlineParser(int argc, const char* const argv[])
{
	mPort = 0;

	parseArgumentList(argc, argv);
}

bool CommandlineParser::isValid() {
	bool isPortValid = (mPort != 0);
	bool isPluginUUIDValid = !mPluginUUID.empty();
	bool isRegisterEventValid = !mRegisterEvent.empty();
	bool isInfoValid = !mInfo.empty();

	return isPortValid
		&& isPluginUUIDValid
		&& isRegisterEventValid
		&& isInfoValid;
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

void CommandlineParser::parseArgumentList(int argc, const char* const argv[])
{
	// assumption - no flag arguments
	int numberOfArguments = (argc - 1) / 2;

	for (int i = 0; i < numberOfArguments; ++i) {
		parseArgument(i, argv);
	}
}

void CommandlineParser::parseArgument(int argumentId, const char* const argv[])
{
	int parameterIndex = argumentId * 2 + 1;
	int valueIndex = parameterIndex + 1;

	std::string parameter(argv[parameterIndex]);
	std::string value(argv[valueIndex]);

	if ("-port" == parameter) {
		mPort = atoi(value.c_str());
	}
	else if ("-pluginUUID" == parameter) {
		mPluginUUID = value;
	}
	else if ("-registerEvent" == parameter) {
		mRegisterEvent = value;
	}
	else if ("-info" == parameter) {
		mInfo = value;
	}
}
