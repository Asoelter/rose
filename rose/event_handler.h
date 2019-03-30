#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <array>
#include <functional>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

class EventHandler
{
	using EventFunction = std::function<void(sf::Drawable*)> ;

public:
	EventHandler(sf::Drawable* object) noexcept;

	void bind(sf::Event::EventType eventType, EventFunction f) noexcept;

	template<typename func>
	void bind(sf::Event::EventType eventType, func f);
	
	static void handle(sf::Event::EventType eventType) noexcept;

private:
	struct EventHandlingInfo
	{
		EventHandlingInfo(sf::Drawable* obj) : object(obj), functions() {}
		sf::Drawable* object;
		std::array<EventFunction, 14> functions;
	};

	std::size_t indexOfObject_;

	static std::vector <EventHandlingInfo> objectFunctionPairs_;
};

//The linker yelled at me until I put this here
template<typename func>
inline void EventHandler::bind(sf::Event::EventType eventType, func f)
{
	EventFunction bindableFunction = f;
	EventHandler::bind(eventType, bindableFunction);
}
#endif //EVENT_HANDLER_H


