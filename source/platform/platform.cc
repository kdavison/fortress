#include "platform.h"
#include <SDL2/SDL.h>
#include <spdlog/spdlog.h>
#include <cassert>

namespace
{

using namespace PLATFORM;

static constexpr MOUSE::Button translate_mouse_button(uint8_t const& raw)
{
  return static_cast<MOUSE::Button>( raw );
}

static constexpr AUDIO::DEVICE::Type translsate_audio_device_type(bool const& raw)
{
  return (raw ? AUDIO::DEVICE::Type::INPUT : AUDIO::DEVICE::Type::OUTPUT);
}

static constexpr int32_t translate_mouse_wheel(int32_t const& value, uint32_t const& direction)
{
  return (value * (static_cast<SDL_MouseWheelDirection>(direction) == SDL_MOUSEWHEEL_NORMAL) ? 1 : (-1));
}

}

namespace PLATFORM
{

Platform::Platform()
  : _window(nullptr)
  , _renderer(nullptr)
{
  /* setup sdl */
  assert(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0);
  SDL_Window *_window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  assert(_window);
  SDL_Renderer *_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  assert(_renderer);

  auto console = spdlog::stdout_color_mt("console");
}

Platform::~Platform()
{
  SDL_DestroyRenderer(_renderer);
  SDL_DestroyWindow(_window);
  SDL_Quit();
}

void Platform::ProcessEvents()
{
  SDL_Event e;
  for(uint32_t count = 0; count < 128 && SDL_PollEvent( &e ); ++count)
  {
    switch(e.type)
    {
    case SDL_QUIT:
      dispatch<EventID::QUIT>();
      break;
    case SDL_SYSWMEVENT:
#if defined(_WIN32)

#elif defined(__linux__)

#elif defined(__APPLE__)

#else
      static_assert(false, "[ERROR?!] What system are you building for?");
#endif
      break;
    case SDL_WINDOWEVENT:
      switch(e.window.event)
      {
      case SDL_WINDOWEVENT_SHOWN:
        dispatch<EventID::WINDOW_SHOWN>();
        break;
      case SDL_WINDOWEVENT_HIDDEN:
        dispatch<EventID::WINDOW_HIDDEN>();
        break;
      case SDL_WINDOWEVENT_EXPOSED:
        dispatch<EventID::WINDOW_EXPOSED>();
        break;
      case SDL_WINDOWEVENT_MOVED:
        dispatch<EventID::WINDOW_MOVED>(
          e.window.data1,
          e.window.data2
        );
        break;
      case SDL_WINDOWEVENT_RESIZED:
        dispatch<EventID::WINDOW_RESIZED>(
          static_cast<uint32_t>(e.window.data1),
          static_cast<uint32_t>(e.window.data2)
        );
        break;
      case SDL_WINDOWEVENT_SIZE_CHANGED:
        dispatch<EventID::WINDOW_SIZE_CHANGED>(
          static_cast<uint32_t>(e.window.data1),
          static_cast<uint32_t>(e.window.data2)
        );
        break;
      case SDL_WINDOWEVENT_MINIMIZED:
        dispatch<EventID::WINDOW_MINIMIZED>();
        break;
      case SDL_WINDOWEVENT_MAXIMIZED:
        dispatch<EventID::WINDOW_MAXIMIZED>();
        break;
      case SDL_WINDOWEVENT_RESTORED:
        dispatch<EventID::WINDOW_RESTORED>();
        break;
      case SDL_WINDOWEVENT_ENTER:
        dispatch<EventID::WINDOW_ENTER>();
        break;
      case SDL_WINDOWEVENT_LEAVE:
        dispatch<EventID::WINDOW_LEAVE>();
        break;
      case SDL_WINDOWEVENT_FOCUS_GAINED:
        dispatch<EventID::WINDOW_FOCUS_GAINED>();
        break;
      case SDL_WINDOWEVENT_FOCUS_LOST:
        dispatch<EventID::WINDOW_FOCUS_LOST>();
        break;
      case SDL_WINDOWEVENT_CLOSE:
        dispatch<EventID::QUIT>();
        break;
      case SDL_WINDOWEVENT_TAKE_FOCUS:
        dispatch<EventID::WINDOW_TAKE_FOCUS>();
        break;
      case SDL_WINDOWEVENT_HIT_TEST:
        dispatch<EventID::WINDOW_HIT_TEST>();
        break;
      default:
        /* log an error */
        break;
      }
      break;
    case SDL_KEYDOWN:
      dispatch<EventID::KEYDOWN>(
          e.key.repeat,
          e.key.keysym.mod,
          static_cast<uint32_t>(e.key.keysym.sym)
      );
      break;
    case SDL_KEYUP:
      dispatch<EventID::KEYUP>(
          e.key.repeat,
          e.key.keysym.mod,
          static_cast<uint32_t>(e.key.keysym.sym)
      );
      break;
    case SDL_MOUSEMOTION:
      dispatch<EventID::MOUSE_MOVE>(
        e.motion.state,
        e.motion.x,
        e.motion.y,
        e.motion.xrel,
        e.motion.yrel
      );
      break;
    case SDL_MOUSEBUTTONDOWN:
      dispatch<EventID::MOUSE_BUTTON_DOWN>(
        translate_mouse_button( e.button.button ),
        e.button.clicks,
        e.button.x,
        e.button.y
      );
      break;
    case SDL_MOUSEBUTTONUP:
      dispatch<EventID::MOUSE_BUTTON_UP>(
        translate_mouse_button( e.button.button ),
        e.button.clicks,
        e.button.x,
        e.button.y
      );
      break;
    case SDL_MOUSEWHEEL:
      dispatch<EventID::MOUSE_WHEEL>(
        translate_mouse_wheel( e.wheel.x, e.wheel.direction ),
        translate_mouse_wheel( e.wheel.y, e.wheel.direction )
      );
      break;
    case SDL_AUDIODEVICEADDED:
      dispatch<EventID::AUDIO_DEVICE_ADDED>(
        e.adevice.which,
        translsate_audio_device_type( e.adevice.iscapture )
      );
    case SDL_AUDIODEVICEREMOVED:
      dispatch<EventID::AUDIO_DEVICE_REMOVED>(
        e.adevice.which,
        translsate_audio_device_type( e.adevice.iscapture )
      );
      break;
    case SDL_RENDER_TARGETS_RESET:
    case SDL_RENDER_DEVICE_RESET:
      dispatch<EventID::RENDER_RESET>();
      break;
    default:
      /* todo user event support */
      break;
    }
  }
}

void Platform::Show()
{
  //First clear the renderer
  SDL_RenderClear(_renderer);

  //Update the screen
  SDL_RenderPresent(_renderer);

  //sleep for a bit
  std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(200));
}

}//::PLATFORM::
