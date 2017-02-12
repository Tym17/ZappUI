//
// Tile.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Fri Jun 24 11:45:44 2016 Tym17
// Last update Sun Jun 26 14:33:29 2016 Tym17
//

#ifndef TILE_HPP_
# define TILE_HPP_

# include <iostream>
# include "SFML/Graphics.hpp"

class TileContent;
class Media;

class Tile
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
  Tile(void);
  Tile(const TileContent &);
  Tile(const Tile &);
  Tile &operator=(const Tile &);
  Tile &operator=(const TileContent &);
  ~Tile(void);

  void	draw(sf::RenderWindow &, const sf::Vector2<int> &, Media &);
};

#endif /* !TILE_HPP_ */
