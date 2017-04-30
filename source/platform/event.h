#ifndef PLATFORM_EVENT_H
#define PLATFORM_EVENT_H

#include "inputConstants.h"

namespace PLATFORM
{

struct iEvent
{
  virtual EventType_t ID() const = 0;
};

template<EventType_t TYPE>
struct BaseEvent
{
  EventType_t ID() const final { return TYPE; }
};

template<EventType_t TYPE>
struct Event
  : public BaseEvent<TYPE>
{
};

}

#endif //#ifndef PLATFORM_EVENT_H
