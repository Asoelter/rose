#include "log.h"
#include <string>

namespace Rose
{

bool Logger::enabled = false;
const std::string Logger::redBegin		= "\033[1;31m";
const std::string Logger::redEnd		= "\033[0m";
const std::string Logger::yellowBegin	= "\033[1;33m";
const std::string Logger::yellowEnd		= "\033[0m";
const std::string Logger::greenBegin	= "\033[1;32m";
const std::string Logger::greenEnd		= "\033[0m";

void Logger::init()
{
	enabled = true;
}

void Logger::error(const std::string& msg)
{
	std::cout << redBegin << msg << redEnd << '\n';
}

void Logger::warn(const std::string& msg)
{
	std::cout << yellowBegin << msg << yellowEnd << '\n';
}

void Logger::info(const std::string& msg)
{
	std::cout << greenBegin << msg << greenEnd << '\n';
}

void Logger::error(const std::string&& msg)
{
	std::cout << redBegin << std::move(msg) << redEnd << std::endl;
}

void Logger::warn(const std::string&& msg)
{
	std::cout << yellowBegin << std::move(msg) << yellowEnd << std::endl;
}

void Logger::info(const std::string&& msg)
{
	std::cout << greenBegin << std::move(msg) << greenEnd << std::endl;
}

}
