#include "rawConversion.h"
#include "inputConstants.h"

template<>
std::unique_ptr<iEvent> SubFactory<SDL_QUIT>::Create(SDL_Event const& e)
{
  return std::make_unique<Event<EventType_t::QUIT>();
}

template<>
std::unique_ptr<iEvent> SubFactory<SDL_SYSWMEVENT>::Create(SDL_Event const& e)
{
  return std::make_unique<Event<EventType_t::SYSTEM>>();
}

