//
// Tile.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Sat Jun 25 11:21:44 2016 Tym17
// Last update Sun Jun 26 16:52:36 2016 Tym17
//

#include "Tile.hpp"
#include "MapEvent.hpp"
#include "Media.hpp"

Tile::Tile(void) :
  x(0), y(0), n(0), l(0), d(0), s(0), m(0), p(0), t(0)
{
}

Tile::Tile(const TileContent &tc) :
  x(tc.getX()), y(tc.getY()), n(tc.getNo()), l(tc.getLi()), d(tc.getDe()),
  s(tc.getSi()), m(tc.getMe()), p(tc.getPh()), t(tc.getTh())
{
}

Tile::Tile(const Tile &tc) :
  x(tc.x), y(tc.y), n(tc.n), l(tc.l), d(tc.d), s(tc.s), m(tc.m), p(tc.p), t(tc.t)
{
}

Tile &Tile::operator=(const Tile &tc)
{
  x = tc.x;
  y = tc.y;
  n = tc.n;
  l = tc.l;
  d = tc.d;
  s = tc.s;
  m = tc.m;
  p = tc.p;
  t = tc.t;
  return *this;
}

Tile &Tile::operator=(const TileContent &tc)
{
  x = tc.getX();
  y = tc.getY();
  n = tc.getNo();
  l = tc.getLi();
  d = tc.getDe();
  s = tc.getSi();
  m = tc.getMe();
  p = tc.getPh();
  t = tc.getTh();
  return *this;
}

Tile::~Tile(void)
{
}

void Tile::draw(sf::RenderWindow &win, const sf::Vector2<int> &mapSize, Media &res)
{
  sf::Vector2<int> tileSize;
  sf::Vector2<int> iconSize;
  int	padding;
  sf::Sprite sprite;

  tileSize.x = (int)(WIN_X / mapSize.x);
  tileSize.y = (int)(WIN_Y / mapSize.y);
  iconSize.x = tileSize.x / 3;
  iconSize.y = tileSize.y / 2;
  if (iconSize.x > iconSize.y)
    iconSize.x = iconSize.y;
  if (iconSize.y > iconSize.x)
    iconSize.y = iconSize.x;
  padding = iconSize.y;

  sprite.setTexture(res.grass);
  sprite.setPosition(x * tileSize.x, y * tileSize.y);
  sprite.setScale(SCALE(tileSize.x, GRASS_SIZE), SCALE(tileSize.y, GRASS_SIZE));
  win.draw(sprite);
  if (n > 0)
    {
      sprite.setTexture(res.food);
      sprite.setTextureRect(sf::IntRect(0, 0, ICON_SIZE, ICON_SIZE));
      sprite.setPosition(x * tileSize.x, y * tileSize.y);
      sprite.setScale(SCALE(iconSize.x, ICON_SIZE), SCALE(iconSize.y, ICON_SIZE));
      win.draw(sprite);
    }

  iconSize.x = tileSize.x / 7;
  iconSize.y = (tileSize.y - padding) / 2;
  if (iconSize.x > iconSize.y)
    iconSize.x = iconSize.y;
  if (iconSize.y > iconSize.x)
    iconSize.y = iconSize.x;
  if (l > 0)
    {
      sprite.setTexture(res.gem);
      sprite.setTextureRect(sf::IntRect(0, 0, ICON_SIZE, ICON_SIZE));
      sprite.setPosition((x * tileSize.x), (y * tileSize.y) + padding);
      sprite.setScale(SCALE(iconSize.x, ICON_SIZE), SCALE(iconSize.y, ICON_SIZE));
      sprite.setColor(sf::Color(255, 200, 120));
      win.draw(sprite);
    }

  if (d > 0)
    {
      sprite.setTexture(res.gem);
      sprite.setTextureRect(sf::IntRect(0, 0, ICON_SIZE, ICON_SIZE));
      sprite.setPosition((x * tileSize.x) + iconSize.x, (y * tileSize.y) + padding);
      sprite.setScale(SCALE(iconSize.x, ICON_SIZE), SCALE(iconSize.y, ICON_SIZE));
      sprite.setColor(sf::Color(150, 150, 255));
      win.draw(sprite);
    }

  if (s > 0)
    {
      sprite.setTexture(res.gem);
      sprite.setTextureRect(sf::IntRect(0, 0, ICON_SIZE, ICON_SIZE));
      sprite.setPosition((x * tileSize.x) + (iconSize.x * 2), (y * tileSize.y) + padding);
      sprite.setScale(SCALE(iconSize.x, ICON_SIZE), SCALE(iconSize.y, ICON_SIZE));
      sprite.setColor(sf::Color(255, 180, 255));
      win.draw(sprite);
    }

  if (m > 0)
    {
      sprite.setTexture(res.gem);
      sprite.setTextureRect(sf::IntRect(0, 0, ICON_SIZE, ICON_SIZE));
      sprite.setPosition((x * tileSize.x), (y * tileSize.y) + iconSize.y + padding);
      sprite.setScale(SCALE(iconSize.x, ICON_SIZE), SCALE(iconSize.y, ICON_SIZE));
      sprite.setColor(sf::Color(200, 200, 255));
      win.draw(sprite);
    }

  if (p > 0)
    {
      sprite.setTexture(res.gem);
      sprite.setTextureRect(sf::IntRect(0, 0, ICON_SIZE, ICON_SIZE));
      sprite.setPosition((x * tileSize.x) + iconSize.x, (y * tileSize.y) + iconSize.y + padding);
      sprite.setScale(SCALE(iconSize.x, ICON_SIZE), SCALE(iconSize.y, ICON_SIZE));
      sprite.setColor(sf::Color(255, 150, 150));
      win.draw(sprite);
    }

  if (t > 0)
    {
      sprite.setTexture(res.gem);
      sprite.setTextureRect(sf::IntRect(0, 0, ICON_SIZE, ICON_SIZE));
      sprite.setPosition((x * tileSize.x) + (iconSize.x * 2), (y * tileSize.y) + iconSize.y + padding);
      sprite.setScale(SCALE(iconSize.x, ICON_SIZE), SCALE(iconSize.y, ICON_SIZE));
      sprite.setColor(sf::Color(255, 255, 255));
      win.draw(sprite);
    }

  return ;
}
