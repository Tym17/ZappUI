//
// App.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Tue Jun 14 14:12:03 2016 Tym17
// Last update Sun Jun 26 21:24:01 2016 Tym17
//

#include "Log.hpp"
#include "App.hpp"
#include "CNet.hpp"

namespace ZappyUi
{

  App::App(CNet &_net, int dx, int dy, const std::string &n) :
    window(sf::VideoMode(dx, dy), n), net(_net), game(_net, window)
  {
    window.setFramerateLimit(60);
  }

  App::~App(void)
  {
  }

  bool	App::isRunning(void) const
  {
    return window.isOpen();
  }

  void	App::render(float dtime)
  {
    window.clear(sf::Color(0, 0, 0));
    game.draw(dtime);
    window.display();
    return ;
  }

  void	App::compute(float dtime)
  {
    (void) dtime;

    return ;
  }

  void	App::handleKeys(const sf::Event &event)
  {
    switch (event.key.code)
      {
      case sf::Keyboard::Escape:
	window.close();
	break ;
      default :
	break ;
      }
    return ;
  }

  void	App::handleEvents(void)
  {
    sf::Event event;
    while (window.pollEvent(event))
      {
	switch (event.type)
	  {
	  case sf::Event::Closed:
	    window.close();
	    break ;
	  case sf::Event::KeyPressed:
	    handleKeys(event);
	    break ;
	  default :
	    break ;
	  }
      }
    return ;
  }

  void	App::handleNet(std::vector<NetEvent *> events)
  {
    game.build(events);
    return ;
  }

  bool	App::isDone(void) const
  {
    return game.isDone();
  }

};
