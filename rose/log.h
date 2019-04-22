#ifndef LOG_H
#define LOG_H

#include <iostream>

//Inspired from theChernoProject's youtube channel

namespace Rose
{
	class Logger
	{
		public:
			static void init();
			static void error(const std::string& msg);
			static void warn(const std::string& msg);
			static void info(const std::string& msg);

			static void error(const std::string&& msg);
			static void warn(const std::string&& msg);
			static void info(const std::string&& msg);

		private:
			static bool enabled;
			static const std::string redBegin;
			static const std::string redEnd;
			static const std::string yellowBegin;
			static const std::string yellowEnd;
			static const std::string greenBegin;
			static const std::string greenEnd;
};
}

#endif //LOG_H
