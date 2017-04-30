#ifndef INPUT_ACTION_H
#define INPUT_ACTION_H

#include "iEvent.h"

namespace INPUT
{

//base definition
template<EventActionId_t T>
class Action
  : public iEvent
{
public:
  Action() = default;
  virtual ~Action() = default;
  EventType_t type() const final { return EventType_t::ACTION; }
  EventId_t id() const final { return static_cast<EventId_t>(T); }
};

}//::INPUT::

#endif //#ifndef INPUT_ACTION_H
