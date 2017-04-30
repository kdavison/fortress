#ifndef PLATFORM_H
#define PLATFORM_H

#include <string>
#include <functional>

#define STRINGIFY(x) (#x)
#define XSTRINGIFY(x) STRINGIFY(x)

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

namespace PLATFORM
{

class Application
{
public:
  Application(std::size_t width, std::size_t height);
  virtual ~Application();

  std::string NAME() const { return std::string(XSTRINGIFY(PROJECT_NAME)); }
  std::string VERSION() const { return std::string(XSTRINGIFY(PROJECT_VERSION)); }
  std::string SYSTEM() const { return std::string(XSTRINGIFY(HOST_SYSTEM_NAME)); }

  void Register(EventType_t type, std::function<void(iEvent const&)> const& handler);

private:
  std::atomic<bool> _quit;
  SDL_Window * _window;
  SDL_Renderer * _renderer;
  SDL_Texture * _texture;
};

}

#endif
