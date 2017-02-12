//
// Media.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Sun Jun 26 14:29:07 2016 Tym17
// Last update Sun Jun 26 22:38:58 2016 Tym17
//

#ifndef MEDIA_HPP_
# define MEDIA_HPP_

# include "Window.hpp"
# include "SFML/Graphics.hpp"

// GRASS    1.0
//   80

# define GRASS_SIZE	1024
# define ICON_SIZE	127
# define GUY_SIZE	120
// X for the wanted size, Y for the image size
# define SCALE(x, y)	((float)((float)x/ (float)y))

class Media
{
public:
  Media(void);
  ~Media(void);

  sf::Texture grass;
  sf::Texture food;
  sf::Texture gem;
  sf::Texture guy_n;
  sf::Texture guy_w;
  sf::Texture guy_e;
  sf::Texture guy_s;
  sf::Texture egg;
  sf::Font    font;

  static sf::Color getTeamColor(const std::string &);
};

#endif /* !MEDIA_HPP_ */
