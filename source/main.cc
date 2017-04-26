#include <spdlog/spdlog.h>
#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

int main()
{
  auto console = spdlog::stdout_color_mt("console");

  try
  {
    SDL2pp::SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL2pp::Window window("libSDL2pp demo",
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                640, 480, SDL_WINDOW_RESIZABLE);
  }
  catch(std::exception& ex)
  {
    console->error(ex.what());
  }

  return 0;
}
