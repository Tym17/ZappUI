//
// App.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Tue Jun 14 13:54:42 2016 Tym17
// Last update Sun Jun 26 21:21:33 2016 Tym17
//

#ifndef APP_HPP_
# define APP_HPP_

# include <string>
# include <vector>
# include "SFML/Graphics.hpp"
# include "Game.hpp"

# define FRAME_LIMIT	60

class NetEvent;
class CNet;

namespace ZappyUi
{

  class App
  {
    sf::RenderWindow	window;
    CNet		&net;
    Game		game;

    void handleKeys(const sf::Event &);

  public:
    App(CNet &net, int, int, const std::string &);
    ~App(void);

    bool isRunning(void) const;
    void render(float dtime);
    void compute(float dtime);
    void handleEvents(void);
    void handleNet(std::vector<NetEvent *>);

    bool isDone(void) const;
  };

};

#endif /* !APP_HPP_ */
