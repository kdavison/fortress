#ifndef PLATFORM_KEYBOARD_EVENT_H
#define PLATFORM_KEYBOARD_EVENT_H

#include "platformEventID.h"
#include <limits>

namespace PLATFORM
{
namespace KEYBOARD
{

enum class Modifier : uint32_t
{
  INVALID = std::numeric_limits<uint32_t>::max(),
  NONE    = std::numeric_limits<uint32_t>::min(),
  LEFT_SHIFT,
  RIGHT_SHIFT,
  LEFT_CONTROL,
  RIGHT_CONTROL,
  LEFT_ALT,
  RIGHT_ALT,
  LEFT_GUI,
  RIGHT_GUI,
  NUMLOCK,
  CAPS,
  MODE,
};

enum class KeyState : uint8_t
{
  INVALID = std::numeric_limits<uint8_t>::max(),
  NONE    = std::numeric_limits<uint8_t>::min(),
  PRESSED,
  RELEASED,
};

enum class KeyCode : uint32_t
{
  INVALID = std::numeric_limits<uint32_t>::max(),
  NONE    = std::numeric_limits<uint32_t>::min(),
};

}//::PLATFORM::KEYBOARD::

namespace EVENT
{

struct Keyboard : public Event<EventID::KEYBOARD>
{
  KEYBOARD::KeyState state;
  KEYBOARD::Modifier modifier;
  uint32_t keycode; //KEYBOARD::KeyCode  keycode; //someday this will be real!
};

}//::PLATFORM::EVENT::

}//::PLATFORM::

#endif
