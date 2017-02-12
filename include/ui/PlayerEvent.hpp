//
// PlayerEvent.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Tue Jun 21 16:11:25 2016 Tym17
// Last update Sat Jun 25 23:12:27 2016 Tym17
//

#ifndef PLAYEREVENT_HPP_
# define PLAYEREVENT_HPP_

# include <iostream>
# include <sstream>
# include <string>
# include "NetEvent.hpp"

// pnw id X Y O L N
class PlayerLogon : public NetEvent
{
  int	id;
  int	x;
  int	y;
  int	o;
  int	l;
  std::string	team;

public:
  PlayerLogon(std::stringstream &stm) :
    NetEvent(), id(0), x(0), y(0), o(0), l(0)
  {
    stm >> id >> x >> y >> o >> l >> team;
  }
  virtual ~PlayerLogon(void) {}

  int	getId(void) const
  { return id; }
  int	getX(void) const
  { return x; }
  int	getY(void) const
  { return y; }
  int	getO(void) const
  { return o; }
  int	getLvl(void) const
  { return l; }
  const std::string 	&getTeam(void) const
  { return team; };
};

// ppo id X Y O
// ? ppo id
class PlayerPos : public NetEvent
{
  int	x;
  int	y;
  int	o;
  int	id;

public:
  PlayerPos(int _id) :
    NetEvent(), x(0), y(0), o(0), id(_id)
  { cmd = "ppo " + std::to_string(_id) + "\n"; }
  PlayerPos(std::stringstream &stm) :
    NetEvent(), x(0), y(0), o(0), id(0)
  {
    stm >> id >> x >> y >> o;
  }
  virtual ~PlayerPos(void) {}

  int	getX(void) const
  { return x; }
  int	getY(void) const
  { return y; }
  int	getId(void) const
  { return id; }
  int	getO(void) const
  { return o; }
};

class PlayerLvl : public NetEvent
{
  int	id;
  int	lvl;

public:
  PlayerLvl(int _id) : NetEvent(), id(_id), lvl(0) { }
  PlayerLvl(std::stringstream &stm) :
    NetEvent(), id(0), lvl(0) { (void) stm; }
  virtual ~PlayerLvl(void) { }

  int	getId(void) const
  { return id; }
  int	getLvl(void) const
  { return lvl; }
};

class PlayerInv : public NetEvent
{
  int	id;
  int	x;
  int	y;
  int	n;
  int	l;
  int	d;
  int	s;
  int	m;
  int	p;
  int	t;

public:
  PlayerInv(int _id) :
    NetEvent(), id(_id), x(0), y(0), n(0), l(0), d(0), s(0), m(0), p(0), t(0)
  { }
  PlayerInv(std::stringstream &stm) :
    NetEvent(), id(0), x(0), y(0), n(0), l(0), d(0), s(0), m(0), p(0), t(0)
  { (void) stm; }
  virtual ~PlayerInv(void) { }

  int	getId(void) const
  { return id; }
  int	getX(void) const
  { return x; }
  int	getY(void) const
  { return y; }
  int	getN(void) const
  { return n; }
  int	getL(void) const
  { return l; }
  int	getD(void) const
  { return d; }
  int	getS(void) const
  { return s; }
  int	getM(void) const
  { return m; }
  int	getP(void) const
  { return p; }
  int	getT(void) const
  { return t; }
};

// pbc
class Broadcast : public NetEvent
{
  int	id;
  std::string bc;

public:
  Broadcast(std::stringstream &stm) :
    NetEvent(), id(0)
  { stm >> id >> bc; }
  virtual ~Broadcast(void) { }

  int getId(void) const
  { return id; }
  std::string getMsg(void) const
  { return bc; }
};

// pdr/pgt
class ResTrigger : public NetEvent
{
  int	id;

public:
  ResTrigger(std::stringstream &stm) :
    NetEvent(), id(0)
  { stm >> id; }
  virtual ~ResTrigger(void) { }

  int	getId(void) const
  { return id; }
};

// pdi
class PlayerDeath : public NetEvent
{
  int	id;

public:
  PlayerDeath(std::stringstream &stm) : NetEvent(), id(0)
  { stm >> id; }
  virtual ~PlayerDeath(void) { }

  int	getId(void) const
  { return id; }
};

// enw
class newEgg : public NetEvent
{
  int	x;
  int	y;
  int	id;
  int	p;

public:
  newEgg(std::stringstream &stm) :
    NetEvent(), x(0), y(0), id(0), p(0)
  { stm >> id >> p >> x >> y; }
  virtual ~newEgg(void) { }

  int	getX(void) const
  { return x; }
  int	getY(void) const
  { return y; }
  int	getId(void) const
  { return id; }
};

// eht
class deadEgg : public NetEvent
{
  int	id;

public:
  deadEgg(std::stringstream &stm) :
    NetEvent(), id(0)
  { stm >> id; }
  virtual ~deadEgg(void) { }

  int	getId(void) const
  { return id; }
};

// seg
class endGame : public NetEvent
{
  std::string team;

public:
  endGame(std::stringstream &stm) :
    NetEvent()
  { stm >> team; }
  virtual ~endGame(void) { }

  std::string getTeam(void) const
  { return team; }
};

#endif /* !PLAYEREVENT_HPP_ */
