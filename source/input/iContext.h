#ifndef INPUT_CONTEXT_H
#define INPUT_CONTEXT_H

#include <SDL2/SDL_events.h>

namespace INPUT
{

using ContextId_t = uint32_t;
using RawInput_t = SDL_Event;
class iContext
{
public:
  iContext() = default;
  virtual ~iContext() = default;
  virtual ContextId_t id() const = 0;
  virtual bool isInputValid(raw_input_t const& input) const = 0;
  virtual MapInput(raw_input_t const& input) const = 0;
};

} //::INPUT::

#endif //#ifndef INPUT_CONTEXT_H
