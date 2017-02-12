//
// Player.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Fri Jun 24 11:44:17 2016 Tym17
// Last update Sun Jun 26 14:32:19 2016 Tym17
//

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <string>
# include "SFML/Graphics.hpp"
# include "PlayerEvent.hpp"

# define O_NORTH	1
# define O_WEST		4
# define O_EAST		2
# define O_SOUTH	3

class Media;

class Player
{
  int	id;
  int	x;
  int	y;
  int	o;
  std::string team;
  bool	alive;

public:
  Player(void);
  Player(const Player &);
  Player &operator=(const Player &);
  Player &operator=(const PlayerLogon &);
  Player &operator=(const PlayerPos &);
  ~Player(void);

  void	kill(void);
  int	getX(void) const;
  int	getY(void) const;
  void	draw(sf::RenderWindow &, const sf::Vector2<int> &, Media &);
};

#endif /* !PLAYER_HPP_ */
