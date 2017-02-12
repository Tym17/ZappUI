//
// NetResource.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Wed Jun 15 11:16:17 2016 Tym17
// Last update Fri Jun 17 10:53:51 2016 Tym17
//

#ifndef NETRESOURCE_HPP_
# define NETRESOURCE_HPP_

# include <sys/types.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>

struct NetResource
{
  struct sockaddr_in	serverCon;
  int			server;
};

#endif /* !NETRESOURCE_HPP_ */
