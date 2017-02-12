//
// Player.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Sat Jun 25 14:32:15 2016 Tym17
// Last update Sun Jun 26 23:05:33 2016 Tym17
//

#include <iostream>
#include "Player.hpp"
#include "PlayerEvent.hpp"
#include "Media.hpp"

Player::Player(void) :
  id(-1), x(0), y(0), o(O_SOUTH), alive(true)
{ }

Player::Player(const Player &_o) :
  id(_o.id), x(_o.x), y(_o.y), o(_o.o), alive(true)
{ }

Player &Player::operator=(const Player &op)
{
  id = op.id;
  x = op.x;
  y = op.y;
  o = op.o;
  team = op.team;
  alive = op.alive;
  return *this;
}

Player &Player::operator=(const PlayerLogon &op)
{
  x = op.getX();
  y = op.getY();
  o = op.getO();
  id = op.getId();
  team = op.getTeam();
  alive = true;
  return *this;
}

Player &Player::operator=(const PlayerPos &op)
{
  x = op.getX();
  y = op.getY();
  o = op.getO();
  id = op.getId();
  alive = true;
  return *this;
}

Player::~Player(void)
{
}

void	Player::draw(sf::RenderWindow &win, const sf::Vector2<int> &mapSize, Media &res)
{
  if (!alive)
    return ;
  sf::Vector2<int> tileSize;
  sf::Vector2<float> scale;
  sf::Sprite sprite;

  tileSize.x = (int)(WIN_X / mapSize.x);
  tileSize.y = (int)(WIN_Y / mapSize.y);
  scale.x = SCALE(tileSize.x, GUY_SIZE);
  scale.y = SCALE(tileSize.y, GUY_SIZE);
  if (scale.x > scale.y)
    scale.x = scale.y;
  if (scale.y > scale.y)
    scale.y = scale.x;

  sprite.setTexture(res.guy_n);
  if (o == O_WEST)
    sprite.setTexture(res.guy_w);
  else if (o == O_EAST)
    sprite.setTexture(res.guy_e);
  else if (o == O_NORTH)
    sprite.setTexture(res.guy_s);
  sprite.setColor(Media::getTeamColor(team));
  sprite.setTextureRect(sf::IntRect(0, 0, GUY_SIZE, GUY_SIZE));
  sprite.setPosition((int)((x * tileSize.x) + ((tileSize.x / 2) - ((scale.x * GUY_SIZE) / 2))),
		     (int)((y * tileSize.y) + ((tileSize.y / 2) - ((scale.y * GUY_SIZE) / 2))));
  sprite.setScale(scale.x, scale.y);
  win.draw(sprite);
  return ;
}

void	Player::kill(void)
{
  alive = false;
  return ;
}

int	Player::getX(void) const
{
  return x;
}

int	Player::getY(void) const
{
  return y;
}
