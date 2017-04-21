#ifndef INTERFACE_GOAL_H
#define INTERFACE_GOAL_H

namespace emotion
{

class iAgent;

class iGoal
{
public:
  iGoal() = default;
  virtual ~iGoal() = default;
  virtual std::string Name() const = 0;
  virtual float Utility() const = 0;
  virtual std::string Description() const = 0;
  virtual std::shared_ptr<iAgent> Owner() const = 0;
};

}

#endif //INTERFACE_GOAL_H
