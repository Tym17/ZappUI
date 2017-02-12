//
// Egg.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Sat Jun 25 14:55:49 2016 Tym17
// Last update Sun Jun 26 14:34:15 2016 Tym17
//

#ifndef EGG_HPP_
# define EGG_HPP_

# include "SFML/Graphics.hpp"
# include "PlayerEvent.hpp"

class Media;

class Egg
{
  int	id;
  int	x;
  int	y;
  bool	alive;

public:
  Egg(void);
  ~Egg(void);

  Egg &operator=(const Egg &);
  Egg &operator=(const newEgg &);

  void	kill(void);
  void	draw(sf::RenderWindow &, const sf::Vector2<int> &, Media &);
};

#endif /* !EGG_HPP_ */
