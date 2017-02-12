//
// Game.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Fri Jun 24 11:37:33 2016 Tym17
// Last update Sun Jun 26 23:35:16 2016 Tym17
//

#include "Window.hpp"
#include "Game.hpp"
#include "CNet.hpp"
#include "MapEvent.hpp"
#include "Tile.hpp"

Game::Game(CNet &_net, sf::RenderWindow &win) :
  mapSize(sf::Vector2<int>(0, 0)), mapInit(false), stop(false), net(_net), window(win)
{
}

Game::~Game(void) { }

void	Game::initMap(NetEvent *event)
{
  MapSize *msize = dynamic_cast<MapSize *>(event);
  if (msize != NULL)
    {
      mapSize.x = msize->getX();
      mapSize.y = msize->getY();
      mapInit = true;
      tile = std::vector< std::vector<Tile> >
	(mapSize.x, std::vector<Tile>(mapSize.y));
    }
  return ;
}

void	Game::fillTile(NetEvent *event)
{
  TileContent *tc = dynamic_cast<TileContent *>(event);
  if (tc != NULL)
    {
      if (tc->getX() < mapSize.x && tc->getY() < mapSize.y)
	tile[tc->getX()][tc->getY()] = *tc;
    }
  return ;
}

void	Game::playerActions(NetEvent *event)
{
  PlayerPos *pp = dynamic_cast<PlayerPos *>(event);
  if (pp != NULL)
    {
      players[pp->getId()] = *pp;
      return ;
    }
  PlayerLogon *pl = dynamic_cast<PlayerLogon *>(event);
  if (pl != NULL)
    {
      players[pl->getId()] = *pl;
      return ;
    }
  ResTrigger *rt = dynamic_cast<ResTrigger *>(event);
  if (rt != NULL)
    {
      net.push(new TileContent(players[rt->getId()].getX(),
			       players[rt->getId()].getY()));
      return ;
    }
  PlayerDeath *pd = dynamic_cast<PlayerDeath *>(event);
  if (pd != NULL)
    players[pd->getId()].kill();
  return ;
}

void	Game::eggActions(NetEvent *event)
{
  newEgg *ne = dynamic_cast<newEgg *>(event);
  if (ne != NULL)
    {
      eggs[ne->getId()] = *ne;
      return ;
    }
  deadEgg *de = dynamic_cast<deadEgg *>(event);
  if (de != NULL)
    eggs[de->getId()].kill();
  return ;
}

void	Game::build(std::vector<NetEvent *> stack)
{
  for (std::vector<NetEvent *>::iterator it = stack.begin();
       it != stack.end(); it = stack.erase(it))
    {
      try
	{
	  initMap(*it);
	  if (mapInit)
	    {
	      fillTile(*it);
	      playerActions(*it);
	      eggActions(*it);
	    }
	  endGame *end = dynamic_cast<endGame *>(*it);
	  if (end != NULL)
	    {
	      stop = true;
	      winners = end->getTeam();
	    }
	}
      catch (std::exception &e)
	{ std::cerr << "[ERROR] " << e.what() << std::endl; }
      delete *it;
    }
  return ;
}

void	Game::draw(float dtime)
{
  (void) dtime;
  for (std::vector< std::vector<Tile> >::iterator it = tile.begin();
       it != tile.end(); it++)
    {
      for (std::vector<Tile>::iterator i = it->begin();
	   i != it->end(); i++)
	i->draw(window, mapSize, res);
    }
  for (std::map<int, Egg>::iterator it = eggs.begin();
       it != eggs.end(); it++)
    it->second.draw(window, mapSize, res);
  for (std::map<int, Player>::iterator it = players.begin();
       it != players.end(); it++)
    it->second.draw(window, mapSize, res);
  if (stop)
    drawVictory();
  return ;
}

sf::Vector2<int> Game::mousePos(int x, int y)
{
  (void) x;
  (void) y;
  return sf::Vector2<int>(0, 0);
}

bool	Game::isDone(void) const
{
  return stop;
}

void	Game::drawVictory(void)
{
  sf::Text text;
  int padding;

  text.setFont(res.font);
  text.setString(winners);
  text.setCharacterSize(64);
  text.setColor(sf::Color(0, 0, 0));
  padding = (WIN_Y / 2) - (text.getGlobalBounds().height / 2);
  text.setPosition((WIN_X / 2) - (text.getGlobalBounds().width / 2),
		   padding);
  padding += text.getGlobalBounds().height;
  window.draw(text);
  text.setColor(sf::Color(255, 200, 0));
  text.move(0, -3);
  window.draw(text);
  text.setColor(sf::Color(0, 0, 0));
  text.setCharacterSize(32);
  text.setString("has won!");
  text.setPosition((WIN_X / 2) - (text.getGlobalBounds().width / 2),
		   padding + text.getGlobalBounds().height + 6);
  window.draw(text);
  text.setColor(sf::Color(255, 200, 0));
  text.move(0, -3);
  window.draw(text);
  return ;
}
