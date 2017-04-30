#ifndef INPUT_RANGE_H
#define INPUT_RANGE_H

#include "iEvent.h"

namespace INPUT
{

template<EventRangeId_t T>
class Range
  : public iEvent
{
public:
  Range(float const& value) : _value(value) { }
  virtual ~Range() = default;
  EventType_t type() const final { return EventType_t::RANGE; }
  EventId_t id() const final { return static_cast<EventId_t>(T); }
  float value() const { return _value; }
private:
  float _value;
};

}//::INPUT::

#endif //#ifndef INPUT_RANGE_H
