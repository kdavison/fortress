#ifndef INPUT_EVENT_ID_H
#define INPUT_EVENT_ID_H

namespace INPUT
{

enum class EventRangeId_t : uint32_t
{
  NONE,
  FINAL
};

enum class EventActionId_t : uint32_t
{
  NONE,
  FINAL
};

enum class EventStateId_t : uint32_t
{
  NONE,
  FINAL
};

using EventId_t = uint32_t;

} //::INPUT::

#endif //#ifndef INPUT_EVENT_ID_H
