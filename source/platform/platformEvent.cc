#include "platformEvent.h"

namespace PLATFORM
{

namespace EVENT
{

/*

I don't actually know what kind of system events we can receive
  but the structures are here to fill in if/when we need them.
*/
#ifdef _WIN32
template<>
struct System<SYSTEM::TYPE::WINDOWS> { };
#elif __linux__
template<>
struct System<SYSTEM::TYPE::X11> { };
#elif __APPLE__
//there are no cocoa specific events
template<>
struct System<SYSTEM::TYPE::COCOA> { };
#else
static_assert(false, "[ERROR]: what system are you on?!");
#endif //end of system definitions

} //::PLATFORM::EVENT::

} //::PLATFORM::
