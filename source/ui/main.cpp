//
// main.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy/source/ui
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Mon Jun 13 15:24:47 2016 Tym17
// Last update Sun Jun 26 21:29:07 2016 Tym17
//

#include <string>
#include <iostream>
#include <sstream>
#include "SFML/System/Clock.hpp"
#include "CNet.hpp"
#include "Log.hpp"
#include "App.hpp"
#include "Window.hpp"
#include "CNetException.hpp"

int	mainloop(char *ip, int port)
{
  sf::Clock	clock;
  sf::Time	time;
  CNet		net(ip, port, true);
  ZappyUi::App	ui(net, WIN_X, WIN_Y, "ZappUI");
  Log		sfmlLogger("sfml", "[SFML]", false);

  clock.restart();
  net.try_connect();
  while (ui.isRunning())
    {
      ui.handleEvents();
      if (!ui.isDone())
	ui.handleNet(net.fetch());
      time = clock.getElapsedTime();
      if (time.asMilliseconds() >= 1000 / FRAME_LIMIT)
	{
	  ui.render(time.asMilliseconds());
	  clock.restart();
	}
      ui.compute(time.asMilliseconds());
    }
  return 0;
}

int	main(int ac, char **av)
{
  int	port;

  if (ac != 3)
    {
      std::cerr << "Usage: ./zappy-ui [ip] [port]" << std::endl;
      return 1;
    }
  std::istringstream (av[2]) >> port;
  try
    {
      mainloop(av[1], port);
    }
  catch (const std::exception &e)
    {
      std::cerr << "Woops !" << std::endl << e.what() << std::endl;
    }
  return 0;
}
