//
// GreetEvent.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Thu Jun 23 10:34:17 2016 Tym17
// Last update Thu Jun 23 10:34:45 2016 Tym17
//

#include "GreetEvent.hpp"

GreetEvent::GreetEvent(void) :
  NetEvent()
{
  cmd = "GRAPHIC\n";
}

GreetEvent::~GreetEvent(void)
{
}
