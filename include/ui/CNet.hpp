//
// CNet.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Tue Jun 14 17:33:46 2016 Tym17
// Last update Tue Jun 21 10:23:04 2016 Tym17
//

#ifndef CNET_HPP_
# define CNET_HPP_

# include <string>
# include <vector>
# include <sys/types.h>
# include "Log.hpp"
# include "CircularBuffer.hpp"

struct NetResource;
class NetEvent;

class CNet
{
  NetResource	*res;
  std::string	ip;
  int		port;
  bool		isConnected;
  bool		reco;
  Log		cnetlogger;
  CircularBuffer	in;
  NetEvent		*actual;
  std::vector<NetEvent *> pending;

  void	handle_io(fd_set &r, fd_set &w);
  std::vector<NetEvent *> eventStacker(void);

public:
  CNet(const std::string &ip, int port, bool reco = true);
  ~CNet(void);

  void	try_connect(void);
  std::vector<NetEvent *> fetch(void);
  void	push(NetEvent *);
};

#endif /* !CNET_HPP_ */
