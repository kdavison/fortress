#include <spdlog/spdlog.h>
#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>

int main()
{
  auto console = spdlog::stdout_color_mt("console");

  console->info(PROJECT_NAME " version " PROJECT_VERSION);

  try
  {
    SDL2pp::SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL2pp::Window window("libSDL2pp demo",
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                640, 480, SDL_WINDOW_RESIZABLE);
    SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Delay(2000);
  }
  catch(SDL2pp::Exception& ex)
  {
    console->error(ex.GetSDLError());
  }
  catch(std::exception& ex)
  {
    console->error(ex.what());
  }

  return 0;
}
