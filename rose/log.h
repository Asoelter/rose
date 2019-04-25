#ifndef LOG_H
#define LOG_H

#include <iostream>

//Inspired from theChernoProject's youtube channel
//#define INIT_LOGGING

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

			template<typename T, typename... Params>
			static void error(T msg, Params... params)
			{
				#ifdef INIT_LOGGING
				std::cout << redBegin << msg << ' ';
				Rose::Logger::error(params...);
				#endif
			}

			template<typename T, typename... Params>
			static void warn(T msg, Params... params)
			{
				#ifdef INIT_LOGGING
				std::cout << yellowBegin << msg << ' ';
				Rose::Logger::warn(params...);
				#endif 
			}

			template<typename T, typename... Params>
			static void info(T msg, Params... params)
			{
				#ifdef INIT_LOGGING
				std::cout << greenBegin << msg << ' ';
				Rose::Logger::info(params...);
				#endif 
			}


		private:
			static void error();
			static void warn();
			static void info();

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
