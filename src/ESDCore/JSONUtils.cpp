#include "pch.h"
#include "JSONUtils.h"

bool JSONUtils::getObjectByName(json &jsonContent, const char* parameterName, json& jsonObject)
{
	std::string strParameterName(parameterName);
	return getObjectByName(jsonContent, strParameterName, jsonObject);
}

bool JSONUtils::getObjectByName(json &jsonContent, std::string& parameterName, json& jsonObject)
{
	// Check desired value exists
	json::const_iterator jsonIterator(jsonContent.find(parameterName));
	if (jsonIterator == jsonContent.end())
		return false;

	// Check value is an array
	if (!jsonIterator->is_object())
		return false;

	// Assign value
	jsonObject = *jsonIterator;

	return true;
}

std::string JSONUtils::getStringByName(json& jsonContent, const char* parameterName, const std::string& defaultValue)
{
	std::string strParameterName(parameterName);
	return getStringByName(jsonContent, strParameterName, defaultValue);
}

std::string JSONUtils::getStringByName(json& jsonContent, std::string& parameterName, const std::string& defaultValue)
{
	// Check desired value exists
	json::const_iterator jsonIterator(jsonContent.find(parameterName));
	if (jsonIterator == jsonContent.end())
		return defaultValue;

	// Check value is a string
	if (!jsonIterator->is_string())
		return defaultValue;

	// return value
	return *jsonIterator;
}
