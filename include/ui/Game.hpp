//
// Game.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Fri Jun 24 10:16:12 2016 Tym17
// Last update Sun Jun 26 21:55:26 2016 Tym17
//

#ifndef GAME_HPP_
# define GAME_HPP_

# include <map>
# include "SFML/Graphics.hpp"
# include "Player.hpp"
# include "Egg.hpp"
# include "Tile.hpp"
# include "Media.hpp"

class CNet;
class NetEvent;

class Game
{
  std::map<int, Player>	players;
  std::map<int, Egg> eggs;
  std::vector< std::vector<Tile> > tile;
  sf::Vector2<int> mapSize;
  bool mapInit;
  bool stop;
  std::string winners;

  CNet &net;
  sf::RenderWindow &window;
  Media	res;

  void	initMap(NetEvent *);
  void	fillTile(NetEvent *);
  void	playerActions(NetEvent *);
  void	eggActions(NetEvent *);
  void	drawVictory(void);

public:
  Game(CNet &, sf::RenderWindow &);
  ~Game(void);

  void	build(std::vector<NetEvent *>);
  void	draw(float dtime);
  sf::Vector2<int> mousePos(int x, int y);
  bool	isDone(void) const;
};

#endif /* !GAME_HPP_ */
