#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

#include "eventType.h"
#include "eventId.h"

namespace INPUT
{

class iEvent
{
public:
  iEvent() = default;
  ~iEvent() = default;
  virtual EventType_t type() const = 0;
  virtual EventId_t id() const = 0;

  const bool operator==(iEvent const& other)
  {
    return (other.type() == this->type())&&(other.id() == this->id());
  }
};

}//::INPUT::

#endif //#ifndef INPUT_EVENT_H
