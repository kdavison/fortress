#ifndef PLATFORM_H
#define PLATFORM_H

#include "platformEventID.h"
#include "platformEventObserver.h"
#include <functional>
#include <unordered_map>
#include <memory>

union SDL_Event;
struct SDL_Window;
struct SDL_Renderer;

namespace PLATFORM
{

class iEventObserver;

class Platform
{
public:
  Platform();

  virtual ~Platform();

  void ProcessEvents();

  void Show();

private:
  SDL_Window * _window;
  SDL_Renderer * _renderer;
};

}//::PLATFORM::

#endif
