#ifndef PLATFORM_EVENT_H
#define PLATFORM_EVENT_H

#include "platformEventID.h"
#include <bitset>
#include <chrono>

namespace PLATFORM
{

template<EventID ID>
struct Event
{
  EventID id() const { return ID; }
  std::chrono::steady_clock::time_point timestamp;
};

namespace MOUSE
{

enum class Button : uint32_t
{
  LEFT,
  RIGHT,
  MIDDLE,
  X1,
  X2,
};

} //::PLATFORM::MOUSE::

namespace SYSTEM
{

enum class TYPE : uint32_t
{
  INVALID = std::numeric_limits<uint32_t>::max(),
  UNKNOWN = std::numeric_limits<uint32_t>::min(),
  WINDOWS, //microsoft windows
  X11,     //most linux flavors
  COCOA,   //apple osx
  UIKIT,   //apple ios
  ANDROID, //google android
};

}//::PLATFORM::SYSTEM

namespace EVENT
{

/** window events **/

struct WindowMoved : public Event<EventID::WINDOW_MOVED>
{
  int32_t x;
  int32_t y;
};

struct WindowResized : public Event<EventID::WINDOW_RESIZED>
{
  uint32_t width;
  uint32_t height;
};

struct WindowSizeChanged : public Event<EventID::WINDOW_SIZE_CHANGED>
{
  uint32_t width;
  uint32_t height;
};

/** mouse events **/
struct MouseMove : public Event<EventID::MOUSE_MOVE>
{
  std::bitset<32> button_state;
  struct absolute_t
  {
    int32_t x;
    int32_t y;
  } absolute;
  struct relative_t
  {
    int32_t x;
    int32_t y;
  } relative;
};

struct MouseButton : public Event<EventID::MOUSE_BUTTON>
{
  MOUSE::Button button;
  bool state; //0 - down, 1 - up
  uint8_t clicks; //0-none, 1-single, 2-double, etc
  struct relative_t
  {
    int32_t x;
    int32_t y;
  } relative;
};

struct MouseWheel : public Event<EventID::MOUSE_WHEEL>
{
  int32_t horizontal;
  int32_t vertical;
};

/** audio events **/
enum class AudioDeviceType : uint8_t
{
  INPUT,
  OUTPUT,
};

struct AudioDevice : public Event<EventID::AUDIO_DEVICE>
{
  uint32_t device_id;
  AudioDeviceType type;
};

/** system events **/
template<SYSTEM::TYPE T>
struct System : public Event<EventID::SYSTEM> { };

} //::PLATFORM::EVENT::

} //::PLATFORM::

#endif //#ifndef PLATFORM_EVENT_H
