//
// MapEvent.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Tue Jun 21 15:43:17 2016 Tym17
// Last update Sat Jun 25 10:25:26 2016 Tym17
//

#ifndef MAPEVENT_HPP_
# define MAPEVENT_HPP_

# include <iostream>
# include <sstream>
# include <string>
# include "NetEvent.hpp"

// msz X Y
// ? msz
class MapSize : public NetEvent
{
  int	x;
  int	y;

public:
  MapSize(void) : NetEvent(), x(0), y(0)
  { cmd = "msz\n"; }
  MapSize(std::stringstream &stm) :
    NetEvent(), x(0), y(0)
  { stm >> x >> y; }
  virtual ~MapSize(void) { }

  int	getX(void) const
  { return x; }
  int	getY(void) const
  { return y; }
};

// bct X Y no li de si me ph th
// ? bct X Y
class TileContent : public NetEvent
{
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
  TileContent(int _x, int _y) :
    NetEvent(), x(_x), y(_y), n(0), l(0), d(0), s(0), m(0), p(0), t(0)
  { cmd = "bct " + std::to_string(_x) + " " + std::to_string(_y) + "\n"; }
  TileContent(std::stringstream &stm) :
    NetEvent(), x(0), y(0), n(0), l(0), d(0), s(0), m(0), p(0), t(0)
  { stm >> x >> y >> n >> l >> d >> s >> m >> p >> t; }
  virtual ~TileContent(void) { }

  int	getX(void) const
  { return x; }
  int	getY(void) const
  { return y; }
  int	getNo(void) const
  { return n; }
  int	getLi(void) const
  { return l; }
  int	getDe(void) const
  { return d; }
  int	getSi(void) const
  { return s; }
  int	getMe(void) const
  { return m; }
  int	getPh(void) const
  { return p; }
  int	getTh(void) const
  { return t; }
};

// tna N
// ? tna
class TeamName : public NetEvent
{
  std::string team;

public:
  TeamName(void) : NetEvent() { cmd = "tna\n"; }
  TeamName(std::stringstream &stm) :
    NetEvent()
  { stm >> team; }
  virtual ~TeamName(void) { }

  const std::string &getName(void) const
  { return team; }
};

#endif /* !MAPEVENT_HPP_ */
