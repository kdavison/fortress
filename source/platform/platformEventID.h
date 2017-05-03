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
  WINDOW_RESTORE,
  WINDOW_ENTER,
  WINDOW_LEAVE,
  WINDOW_FOCUS_GAINED,
  WINDOW_FOCUS_LOST,
  WINDOW_CLOSE,
  WINDOW_TAKE_FOCUS,
/* system event */
  SYSTEM,
/* audio device event */
  AUDIO_DEVICE,
/* render device events */
  RENDER_DEVICE_RESET,
  RENDER_TARGET_RESET,
/* user events */
  USER,
/* keyboard events */
  KEYBOARD,
/* mouse events */
  MOUSE_MOVE,
  MOUSE_BUTTON,
  MOUSE_WHEEL,
};

}

#endif //#ifndef PLATFORM_EVENT_ID_H
