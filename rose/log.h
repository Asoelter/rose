#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>

//Inspired from theChernoProject's youtube channel

namespace Rose
{
	class Logger
	{
		public:
			/**
			 * @brief Initializes the logging ability (depricated)
			 * 
			 */
			static void init();

			/**
			 * @brief Displays the message in the terminal 
			 * in red text
			 * 
			 * @param msg The message to display
			 */
			static void error(const std::string& msg);

			/**
			 * @brief Displays the message in the terminal 
			 * in yellow text
			 * 
			 * @param msg The message to display
			 */
			static void warn(const std::string& msg);

			/**
			 * @brief Displays the message in the terminal 
			 * in green text
			 * 
			 * @param msg The message to display
			 */
			static void info(const std::string& msg);

			/**
			 * @brief Displays the message in the terminal 
			 * in red text
			 * 
			 * @param msg The message to display
			 */
			static void error(const std::string&& msg);

			/**
			 * @brief Displays the message in the terminal 
			 * in yellow text
			 * 
			 * @param msg The message to display
			 */
			static void warn(const std::string&& msg);

			/**
			 * @brief Displays the message in the terminal 
			 * in green text
			 * 
			 * @param msg The message to display
			 */
			static void info(const std::string&& msg);

			/**
			 * @brief Displays the message and the following
			 * parameters to the terminal in red text
			 * 
			 * @tparam T The type of message to display 
			 * (must have ostream operator)
			 * 
			 * @tparam Params A variadic parameter that can
			 * contain any number of any type of additional 
			 * messages to display 
			 * 
			 * @param msg The first message to display 
			 * 
			 * @param params The following messages to display
			 */
			template<typename T, typename... Params>
			static void error(T msg, Params... params)
			{
				std::cout << redBegin << msg << ' ';
				Rose::Logger::error(params...);
			}

					/**
			 * @brief Displays the message and the following
			 * parameters to the terminal in yellow text
			 * 
			 * @tparam T The type of message to display 
			 * (must have ostream operator)
			 * 
			 * @tparam Params A variadic parameter that can
			 * contain any number of any type of additional 
			 * messages to display 
			 * 
			 * @param msg The first message to display 
			 * 
			 * @param params The following messages to display
			 */
			template<typename T, typename... Params>
			static void warn(T msg, Params... params)
			{
				std::cout << yellowBegin << msg << ' ';
				Rose::Logger::warn(params...);
			}

					/**
			 * @brief Displays the message and the following
			 * parameters to the terminal in green text
			 * 
			 * @tparam T The type of message to display 
			 * (must have ostream operator)
			 * 
			 * @tparam Params A variadic parameter that can
			 * contain any number of any type of additional 
			 * messages to display 
			 * 
			 * @param msg The first message to display 
			 * 
			 * @param params The following messages to display
			 */
			template<typename T, typename... Params>
			static void info(T msg, Params... params)
			{
				std::cout << greenBegin << msg << ' ';
				Rose::Logger::info(params...);
			}


		private:
			/**
			 * @brief A helper function that stops the recursion
			 * of the variadic error function
			 * 
			 */
			static void error();

			/**
			 * @brief A helper function that stops the recursion
			 * of the variadic warn function
			 * 
			 */
			static void warn();

			/**
			 * @brief A helper function that stops the recursion
			 * of the variadic info function
			 * 
			 */
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
