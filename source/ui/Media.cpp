//
// Media.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Sun Jun 26 14:29:57 2016 Tym17
// Last update Sun Jun 26 22:47:45 2016 Tym17
//

#include <stdlib.h>
#include <iostream>
#include "Media.hpp"

Media::Media(void)
{
  std::cout << "[MEDIA]Loading media resources ..." << std::endl;

  if (!grass.loadFromFile("resource/grass.png"))
    std::cerr << "[MEDIA]Could not load grass" << std::endl;
  else
    {
      grass.setSmooth(true);
      grass.setRepeated(false);
    }

  if (!food.loadFromFile("resource/bouffe.png"))
    std::cerr << "[MEDIA]Could not load food" << std::endl;
  else
    {
      food.setSmooth(true);
      food.setRepeated(false);
    }

  if (!gem.loadFromFile("resource/gem.png"))
    std::cerr << "[MEDIA]Could not load gem" << std::endl;
  else
    {
      gem.setSmooth(true);
      gem.setRepeated(false);
    }

  if (!guy_n.loadFromFile("resource/guy.png"))
    std::cerr << "[MEDIA]Could not load guy" << std::endl;
  else
    {
      guy_n.setSmooth(true);
      guy_n.setRepeated(false);
    }

  if (!guy_s.loadFromFile("resource/guy_back.png"))
    std::cerr << "[MEDIA]Could not load guy_back" << std::endl;
  else
    {
      guy_s.setSmooth(true);
      guy_s.setRepeated(false);
    }

  if (!guy_w.loadFromFile("resource/guy_left.png"))
    std::cerr << "[MEDIA]Could not load guy_left" << std::endl;
  else
    {
      guy_w.setSmooth(true);
      guy_w.setRepeated(false);
    }

  if (!guy_e.loadFromFile("resource/guy_right.png"))
    std::cerr << "[MEDIA]Could not load guy_right" << std::endl;
  else
    {
      guy_e.setSmooth(true);
      guy_e.setRepeated(false);
    }

  if (!egg.loadFromFile("resource/egg.png"))
    std::cerr << "[MEDIA]Could not load egg" << std::endl;
  else
    {
      egg.setSmooth(true);
      egg.setRepeated(false);
    }

  if (!font.loadFromFile("resource/ArchitectsDaughter.ttf"))
    std::cerr << "[MEDIA]Could not load font" << std::endl;

  std::cout << "[MEDIA]Resources loaded !" << std::endl;
}

Media::~Media(void)
{
}

sf::Color Media::getTeamColor(const std::string &s)
{
  unsigned int	streamhash = 0;
  int	clr;

  for (std::string::const_iterator it = s.begin(); it != s.end();
       it++)
    streamhash = streamhash * 7 + *it;
  srandom(streamhash);
  clr = random();
  return sf::Color(clr >> 16 & 0xFF,
		   clr >> 8 & 0xFF,
		   clr & 0xFF);
}
