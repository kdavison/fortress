#include "application.h"
#include <spdlog/spdlog.h>
#include <SDL2/SDL.h>

namespace SDL
{

template<typename T, typename... ARGS>
void cleanup(T *t, ARGS&&... args)
{
  cleanup(t);
  cleanup(std::forward<ARGS>(args)...);
}

template<>
void cleanup<SDL_Window>(SDL_Window *window)
{
  if(window)
  {
    SDL_DestroyWindow(window);
  }
}

template<>
void cleanup<SDL_Renderer>(SDL_Renderer *renderer)
{
  if(renderer)
  {
    SDL_DestroyRenderer(renderer);
  }
}

template<>
void cleanup<SDL_Texture>(SDL_Texture *texture)
{
  if(texture)
  {
    SDL_DestroyTexture(texture);
  }
}

template<>
void cleanup<SDL_Surface>(SDL_Surface *surface)
{
  if(surface)
  {
    SDL_FreeSurface(surface);
  }
}

}

namespace PLATFORM
{

static constexpr uint32_t MAX_POLLING_ATTEMPTS = 200;

Application::Application(std::size_t width, std::size_t height)
  : _quit( false )
  , _window( nullptr )
  , _renderer( nullptr )
  , _texture( nullptr )
{
  uint32_t ret = SDL_Init( SDL_INIT_VIDEO );
  if( ret != 0 )
  {
    spdlog::get("console")->error("SDL failed {0}", ret);
    throw std::runtime_error("SDL initialization failed");
  }

  _window = SDL_CreateWindow( NAME().c_str(),
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width, height,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
                            );
  if(_window == nullptr)
  {
    spdlog::get("console")->error("SDL Window failed");
    throw std::runtime_error("SDL window creation failed");
  }

  _renderer = SDL_CreateRenderer( _window, -1, SDL_RENDERER_ACCELERATED );
  if(_renderer == nullptr)
  {
    spdlog::get("console")->error("SDL Renderer failed");
    throw std::runtime_error("SDL renderer creation failed");
  }
}

Application::~Application()
{
  SDL::cleanup(_texture, _renderer, _window);
  SDL_Quit();
}

void Application::ProcessEvent()
{
  SDL_Event e;
  while( !_quit )
  {
    while(SDL_PollEvent(&e))
    {
      static_cast<T&>(e);
    }
  }
}

} //::PLATFORM::
