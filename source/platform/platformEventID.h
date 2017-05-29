#ifndef PLATFORM_EVENT_ID_H
#define PLATFORM_EVENT_ID_H

#include <cstdint>
#include <limits>

namespace PLATFORM
{

enum class EventID : uint32_t
{
  INVALID = std::numeric_limits<uint32_t>::max(),
  NONE    = std::numeric_limits<uint32_t>::min(),
  QUIT,
/* window events */
  WINDOW_SHOWN,
  WINDOW_HIDDEN,
  WINDOW_EXPOSED,
  WINDOW_MOVED,
  WINDOW_RESIZED,
  WINDOW_SIZE_CHANGED,
  WINDOW_MINIMIZED,
  WINDOW_MAXIMIZED,
  WINDOW_RESTORED,
  WINDOW_ENTER,
  WINDOW_LEAVE,
  WINDOW_FOCUS_GAINED,
  WINDOW_FOCUS_LOST,
  WINDOW_TAKE_FOCUS,
  WINDOW_HIT_TEST,
/* system event */
  SYSTEM,
/* audio device event */
  AUDIO_DEVICE_ADDED,
  AUDIO_DEVICE_REMOVED,
/* render device events */
  RENDER_RESET,
/* user events */
  USER,
/* keyboard events */
  KEYDOWN,
  KEYUP,
/* mouse events */
  MOUSE_MOVE,
  MOUSE_BUTTON_DOWN,
  MOUSE_BUTTON_UP,
  MOUSE_WHEEL,
};

namespace AUDIO
{
namespace DEVICE
{

enum class Type : uint8_t
{
  INVALID = std::numeric_limits<uint8_t>::max(),
  NONE    = std::numeric_limits<uint8_t>::min(),
  INPUT,
  OUTPUT
};

}//::PLATFORM::AUDIO::DEVICE::
}//::PLATFORM::AUDIO::

namespace MOUSE
{

enum class Button : uint8_t
{
  INVALID = std::numeric_limits<uint8_t>::max(),
  LEFT    = std::numeric_limits<uint8_t>::min(),
  MIDDLE,
  RIGHT,
  X1,
  X2,
};

}//::PLATFORM::MOUSE::

}//::PLATFORM::

#endif //#ifndef PLATFORM_EVENT_ID_H
