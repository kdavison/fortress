#ifndef WMEVENT_HANDLING
#define WMEVENT_HANDLING

#include <functional>
#include <list>
#include <SDL2/SDL.h>
#include <unordered_map>

class WindowEvent
{
public:
  using event_t = uint32_t;
  using event_handle_t = std::function<void(SDL_Event const& event)>;

  void Register(event_t event, event_handle_t handler)
  {
    _event_handlers[event] = handler;
  }

  void UnRegister(event_t event, event_handle_t handler)
  {
    _event_handlers.erase(event);
  }

  void process()
  {
    uint32_t count = 1;
    SDL_Event _event;
    while(SDL_PollEvent(&_event))
    {
      printf("(%d)\n", count++);
      if( _event_handlers.count( _event.type ) )
      {
        _event_handlers.at( _event.type )( _event );
      }
      else
      {
        //unhandled event
      }
    }
  }

private:
  std::unordered_map<uint32_t, event_handle_t> _event_handlers;
};

/*
namespace EVENT_HANDLING
{

using event_handle_t = std::function<bool(SDL_Event const& event)>;

namespace EVENT
{
  event_handle_t QUIT = [](SDL_Event const& event) { return true; };
  event_handle_t EMPTY = [](SDL_Event const& event) { return false; };
}

static const std::unordered_map<uint32_t, event_handle_t> EVENT_TABLE =
{
  {SDL_WINDOWEVENT, EVENT::EMPTY},
  {SDL_KEYDOWN, EVENT::EMPTY},
  {SDL_KEYUP, EVENT::EMPTY},

  {SDL_TEXTEDITING, EVENT::EMPTY},
  {SDL_TEXTINPUT, EVENT::EMPTY},

  {SDL_MOUSEMOTION, EVENT::EMPTY},
  {SDL_MOUSEBUTTONDOWN, EVENT::EMPTY},
  {SDL_MOUSEBUTTONUP, EVENT::EMPTY},
  {SDL_MOUSEWHEEL, EVENT::EMPTY},

  {SDL_JOYAXISMOTION, EVENT::EMPTY},
  {SDL_JOYBALLMOTION, EVENT::EMPTY},
  {SDL_JOYHATMOTION, EVENT::EMPTY},
  {SDL_JOYBUTTONDOWN, EVENT::EMPTY},
  {SDL_JOYBUTTONUP, EVENT::EMPTY},
  {SDL_JOYDEVICEADDED, EVENT::EMPTY},
  {SDL_JOYDEVICEREMOVED, EVENT::EMPTY},

  {SDL_CONTROLLERAXISMOTION, EVENT::EMPTY},
  {SDL_CONTROLLERBUTTONDOWN, EVENT::EMPTY},
  {SDL_CONTROLLERBUTTONUP, EVENT::EMPTY},
  {SDL_CONTROLLERDEVICEADDED, EVENT::EMPTY},
  {SDL_CONTROLLERDEVICEREMOVED, EVENT::EMPTY},
  {SDL_CONTROLLERDEVICEREMAPPED, EVENT::EMPTY},

  {SDL_AUDIODEVICEADDED, EVENT::EMPTY},
  {SDL_AUDIODEVICEREMOVED, EVENT::EMPTY},

  {SDL_QUIT, EVENT::QUIT},

  {SDL_SYSWMEVENT, EVENT::EMPTY},

  {SDL_FINGERMOTION, EVENT::EMPTY},
  {SDL_FINGERDOWN, EVENT::EMPTY},
  {SDL_FINGERUP, EVENT::EMPTY},

  {SDL_MULTIGESTURE, EVENT::EMPTY},
  {SDL_DOLLARGESTURE, EVENT::EMPTY},
  {SDL_DOLLARRECORD, EVENT::EMPTY},

  {SDL_DROPFILE, EVENT::EMPTY},
  {SDL_DROPTEXT, EVENT::EMPTY},
  {SDL_DROPBEGIN, EVENT::EMPTY},
  {SDL_DROPCOMPLETE, EVENT::EMPTY}
};

void process(bool &should_quit)
{
  SDL_Event event;
  while(SDL_PollEvent(&event))
  {
    if( EVENT_TABLE.count( event.type ) )
    {
      should_quit = EVENT_TABLE.at(event.type)(event);
    }
    else
    {
      //user event or unhandled
    }
  }
}

}
*/
#endif
