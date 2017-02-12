//
// Egg.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Sat Jun 25 15:06:23 2016 Tym17
// Last update Sun Jun 26 23:05:20 2016 Tym17
//

#include "Egg.hpp"
#include "Media.hpp"

Egg::Egg(void) :
  id(-1), x(0), y(0), alive(true)
{
}

Egg::~Egg(void)
{
}

Egg &Egg::operator=(const Egg &e)
{
  id = e.id;
  x = e.x;
  y = e.y;
  alive = e.alive;
  return *this;
}

Egg &Egg::operator=(const newEgg &e)
{
  id = e.getId();
  x = e.getX();
  y = e.getY();
  return *this;
}

void	Egg::kill(void)
{
  alive = false;
  return ;
}

void	Egg::draw(sf::RenderWindow &win, const sf::Vector2<int> &mapSize, Media &res)
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

  sprite.setTexture(res.egg);
  sprite.setTextureRect(sf::IntRect(0, 0, GUY_SIZE, GUY_SIZE));
  sprite.setPosition((int)((x * tileSize.x) + ((tileSize.x / 2) - ((scale.x * GUY_SIZE) / 2))),
		     (int)((y * tileSize.y) + ((tileSize.y / 2) - ((scale.y * GUY_SIZE) / 2))));
  sprite.setScale(scale.x, scale.y);
  win.draw(sprite);
  return ;
}
