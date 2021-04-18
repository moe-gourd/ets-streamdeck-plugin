#pragma once

#include <nlohmann\json.hpp>
using json = nlohmann::json;

class JSONUtils
{
public:
	static bool getObjectByName(json &jsonContent, const char *parameterName, json& jsonObject);
	static bool getObjectByName(json &jsonContent, std::string& parameterName, json& jsonObject);
	static std::string getStringByName(json& jsonContent, const char *parameterName, const std::string& defaultValue = "");
	static std::string getStringByName(json &jsonContent, std::string& parameterName, const std::string& defaultValue = "");
};

