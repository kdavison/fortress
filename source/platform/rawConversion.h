#ifndef RAW_CONVERSION_H
#define RAW_CONVERSION_H

#include <SDL2/SDL_events.h>
#include "inputConstants.h"
#include "event.h"

namespace PLATFORM
{

class iSubFactory
{
public:
  virtual SDL_EventType type() const = 0;
  virtual std::unique_ptr<iEvent> Create(SDL_Event const& e) = 0;
};

template<SDL_EventType TYPE>
class SubFactory
  : public iSubFactory
{
public:
  SDL_EventType type() const final { return TYPE; }
};

class Factory
{
public:
  void Register(std::unique_ptr<iSubFactory> factory)
  {
    _factories.emplace(factory->type(), std::move(factory));
  }

  std::unique_ptr<iEvent> Create(SDL_Event const& e)
  {
    if( _factories.count(e.type) > 0 )
    {
      return _factories.at(e.type)->Create( e );
    }
    else
    {
      return nullptr;
    }
  }

private:
  std::unordered_map<SDL_EventType, std::unique_ptr<iSubFactory>> _factories;
};

}

#endif //#ifndef RAW_CONVERSION_H
