#ifndef PLATFORM_EVENTS_H
#define PLATFORM_EVENTS_H

#include <limits>

namespace PLATFORM
{

enum class EventType_t : uint32_t
{
  INVALID = std::numeric_limits<typename std::underlying_type<EVENT>::type>::max(), //used for range checking
  NONE = std::numeric_limits<typename std::underlying_type<EVENT>::type>::min(),    //basically not used
/* quit message */
  QUIT,
/* window events */
  WINDOW_SHOW,
  WINDOW_HIDDEN,
  WINDOW_EXPOSED,
  WINDOW_MOVED,
  WINDOW_RESIZED,
  WINDOW_CHANGED,
  WINDOW_MINIMIZED,
  WINDOW_MAXIMIZED,
  WINDOW_RESTORED,
  WINDOW_ENTER,
  WINDOW_LEAVE,
  WINDOW_FOCUS_LOST,
  WIDNOW_CLOSE,
  WINDOW_TAKE_FOCUS,
  WINDOW_HIT_TEST,
/* system events */
  SYSTEM,
/* mouse events */
  MOUSE_MOVE,
  MOUSE_BUTTON,
  MOUSE_WHEEL,
/* keyboard events */
  KEYBOARD_KEYDOWN,
  KEYBOARD_KEYUP,
/* joystick events */
  JOY_AXIS,
  JOY_BALL,
  JOY_HAT,
  JOY_BUTTON,
  JOY_DEVICE_ADDED,
  JOY_DEVICE_REMOVED,
/* controller events */
  CONTROLLER_AXIS_MOTION,
  CONTROLLER_BUTTON_DOWN,
  CONTROLLER_BUTTON_UP,
  CONTROLLER_DEVICE_ADDED,
  CONTROLLER_DEVICE_REMOVED,
/* audio events */
  AUDIO_DEVICE_ADDED,
  AUDIO_DEVICE_REMOVED,
/* render events */
  RENDER_TARGET_RESET,
  RENDER_DEVICE_RESET,
/* user events */
  USER
};

}

#endif
