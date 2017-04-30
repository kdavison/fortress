#include "event.h"
#include "inputConstants.h"

namespace PLATFORM
{

template<>
struct Event<EventType_t::QUIT> { };

template<>
struct Event<EventType_t::SYSTEM>
{
  
};

}
