//
// NetEvent.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Mon Jun 20 16:32:14 2016 Tym17
// Last update Sun Jun 26 23:17:21 2016 Tym17
//

#include <iostream>
#include "NetEvent.hpp"
#include "MapEvent.hpp"
#include "PlayerEvent.hpp"

NetEvent::NetEvent(void) : idx(0)
{
}

NetEvent::NetEvent(const NetEvent &o) :
  cmd(o.cmd), idx(o.idx)
{
}

NetEvent &NetEvent::operator=(const NetEvent &o)
{
  cmd = o.cmd;
  idx = o.idx;
  return *this;
}

NetEvent::~NetEvent(void)
{
}

const char	*NetEvent::c_str(void) const
{
  return cmd.c_str();
}

void	NetEvent::inc(int cnt)
{
  if ((size_t) cnt <= cmd.size())
    cmd.erase(cmd.begin(), cmd.begin() + cnt);
  return ;
}

bool	NetEvent::isDone(void) const
{
  if (cmd.size() == 0)
    return true;
  return false;
}

NetEvent *NetEvent::cr_map(const std::string &type, std::stringstream &arg)
{
  if (type == "msz")
    return new MapSize(arg);
  else if (type == "bct")
    return new TileContent(arg);
  else if (type == "tna")
    return new TeamName(arg);
  return new NetEvent;
}

NetEvent *NetEvent::cr_pl(const std::string &type, std::stringstream &arg)
{
  if (type == "pnw")
    return new PlayerLogon(arg);
  else if (type == "ppo")
    return new PlayerPos(arg);
  else if (type == "pbc")
    return new Broadcast(arg);
  else if (type == "pdr" || type == "pgt")
    return new ResTrigger(arg);
  else if (type == "pdi")
    return new PlayerDeath(arg);
  return new NetEvent;
}

NetEvent *NetEvent::cr_egg(const std::string &type, std::stringstream &arg)
{
  if (type == "enw")
    return new newEgg(arg);
  else if (type == "eht")
    return new deadEgg(arg);
  return new NetEvent;
}

NetEvent *NetEvent::create(const std::string &type, std::stringstream &arg)
{
  std::cout << "[NetEvent]" << type << " with : " << arg.str() << std::endl;
  if (type == "msz" || type == "bct" || type == "tna")
    return cr_map(type, arg);
  else if (type == "pnw" || type == "ppo" || type == "pbc" || type == "pdr"
	   || type == "pgt" || type == "pdi")
    return cr_pl(type, arg);
  else if (type == "enw" || type == "eht")
    return cr_egg(type, arg);
  else if (type == "seg")
    return new endGame(arg);
  return new NetEvent;
}
