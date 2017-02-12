//
// GreetEvent.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Thu Jun 23 10:30:33 2016 Tym17
// Last update Thu Jun 23 10:34:04 2016 Tym17
//

#ifndef GREETEVENT_HPP_
# define GREETEVENT_HPP_

# include "NetEvent.hpp"

class GreetEvent : public NetEvent
{
public:
  GreetEvent(void);
  virtual ~GreetEvent(void);
};

#endif /* !GREETEVENT_HPP_ */
