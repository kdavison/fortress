#ifndef GOAL_H
#define GOAL_H

#include "iGoal.h"

namespace emotion
{

class Goal
  : public iGoal
{
public:
  Goal(std::string name, float utility, std::shared_ptr<iAgent> spAgent, std::string description);
  virtual ~Goal();
  std::string Name() const final;
  float Utility() const final;
  std::string Description() const final;
  std::shared_ptr<iAgent> Owner() const final;
private:
  std::string m_name;
  std::string m_description;
  float m_utility;
  std::shared_ptr<iAgent> m_owner;
};

}

#endif //GOAL_H
