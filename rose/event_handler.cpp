#include "event_handler.h"

std::vector <EventHandler::EventHandlingInfo> EventHandler::objectFunctionPairs_;

EventHandler::EventHandler(sf::Drawable* object) noexcept
	: indexOfObject_(0)
{
	objectFunctionPairs_.push_back(EventHandlingInfo(object));
	indexOfObject_ = objectFunctionPairs_.size() - 1;
}

void EventHandler::bind(sf::Event::EventType eventType,  EventFunction f) noexcept
{
	objectFunctionPairs_[indexOfObject_].functions[eventType] = f;
}


void EventHandler::handle(sf::Event::EventType eventType) noexcept
{
	for (auto& it : objectFunctionPairs_)
	{
		auto func = it.functions[eventType];
		func(it.object);
	}
}
