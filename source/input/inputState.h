#ifndef INPUT_STATE_H
#define INPUT_STATE_H

#include "iEvent.h"

namespace INPUT
{

template<EventStateId_t T>
class State
  : public iEvent
{
public:
  State(bool value) : _value(value) { }
  virtual ~State() = default;
  EventType_t type() const final { return EventType_t::STATE; }
  EventId_t id() const final { return static_cast<EventId_t>(T); }
  bool value() const { return _value; }
private:
  const bool _value;
};

} //::INPUT::

#endif //#ifndef INPUT_STATE_H
