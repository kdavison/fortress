#include <spdlog/spdlog.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>

#include "input/input.h"

#include <functional>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <cmath>

int main()
{
  auto console = spdlog::stdout_color_mt("console");
  console->info(PROJECT_NAME " version " PROJECT_VERSION);

  //setup SDL stuff

  bool quit = false;
  while( !quit )
  {
    
/*
  process_events()
    window_manager->process_events();
      this handles like close etc.
    input_manager->process_events();
      entityx.input_system.raise( ... );
      entityx.gui_system.raise( ... );
    network_manager->process_events();
      entityx.networksystem.raise( ... );

  game_logic();
    entityx.systems[ ... ].process();

  render();
    scene->render( tex.new );
    gui->render( tex.new );
    gpu->flip( tex.old, tex.new );
*/
  }

  return 0;
}
