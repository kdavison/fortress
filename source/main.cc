#include "platform/application.h"
#include <spdlog/spdlog.h>
#include <memory>

int main()
{
  auto console = spdlog::stdout_color_mt("console");

/*
  bool quit = false;
  while( !quit )
  {
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
  }
*/

/*

1. collect all input events from OS/Hardware
2. feed raw input into context chain
     raw -> context -> normalized events
3. feed list of events to application code

*/

  return 0;
}
