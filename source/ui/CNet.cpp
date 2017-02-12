//
// CNet.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Wed Jun 15 11:32:12 2016 Tym17
// Last update Sun Jun 26 21:42:46 2016 Tym17
//

#include <iostream>
#include <sstream>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "NetResource.hpp"
#include "CNetException.hpp"
#include "CNet.hpp"
#include "NetEvent.hpp"
#include "GreetEvent.hpp"

static ReadError readerror;
static WriteError writeerror;
static SocketError socketerror;
static ConnectError connecterror;
static FdSock fdsock;
static FdError fderror;

CNet::CNet(const std::string &i, int p, bool rec) :
  res(new NetResource), ip(i), port(p), reco(rec),
  cnetlogger("cnet", "[CNET]", false), actual(NULL)
{
}

CNet::~CNet(void)
{
  close(res->server);
  Log::in("cnet", "Disconneted");
  delete res;
}

void	CNet::try_connect(void)
{
  struct protoent	*pe;

  pe = getprotobyname("TCP");
  if ((res->server = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == ERR_CODE)
    throw socketerror;
  res->serverCon.sin_family = AF_INET;
  res->serverCon.sin_port = htons(port);
  res->serverCon.sin_addr.s_addr = inet_addr(ip.c_str());
  if (connect(res->server, (struct sockaddr *)&(res->serverCon),
	      sizeof(res->serverCon)) == ERR_CODE)
    {
      Log::in("cnet", strerror(errno));
      if (close(res->server) == ERR_CODE)
	throw fderror;
      throw connecterror;
    }
  Log::in("cnet", "Connected.");
  return ;
}

std::vector<NetEvent *> CNet::fetch(void)
{
  fd_set			readfs;
  fd_set			writefs;
  struct timeval		timeout;

  timeout.tv_usec = 50;
  timeout.tv_sec = 0;
  FD_ZERO(&readfs);
  FD_ZERO(&writefs);
  FD_SET(res->server, &readfs);
  FD_SET(res->server, &writefs);
  if (select(res->server + 1, &readfs, &writefs, NULL, &timeout) == ERR_CODE)
    throw connecterror;
  handle_io(readfs, writefs);
  return eventStacker();
}

void	CNet::push(NetEvent *evt)
{
  pending.push_back(evt);
  return ;
}

void	CNet::handle_io(fd_set &rfs, fd_set &wfs)
{
  char	buff[512] = { 0 };
  int	ret = 0;

  if (FD_ISSET(res->server, &rfs))
    {
      ret = read(res->server, buff, 511);
      if (ret == ERR_CODE || ret == 0)
	throw readerror;
      in << buff;
    }
  if (FD_ISSET(res->server, &wfs))
    {
      if (actual == NULL && pending.size() > 0)
	{
	  actual = *(pending.begin());
	  pending.erase(pending.begin());
	}
      if (actual != NULL)
	{
	  if (!actual->isDone())
	    {
	      ret = write(res->server, actual->c_str(), strlen(actual->c_str()));
	      if (ret == ERR_CODE || ret == 0)
		throw writeerror;
	      actual->inc(ret);
	    }
	  else
	    {
	      delete actual;
	      actual = NULL;
	    }
	}
    }
  return ;
}

std::vector<NetEvent *> CNet::eventStacker(void)
{
  std::vector<NetEvent *>	stack;
  std::stringstream		stream;
  std::string			cmd;
  std::string			tmpstream;

  while (in.getRead() != in.getWrite() && *(stream.str().end() - 1) != '\n')
    {
      stream.clear();
      stream.str(in.extract());
      if (*(stream.str().end() - 1) != '\n')
	{
	  //Log::in("cnet", "Recieved: " + stream.str());
	  stream >> cmd;
	  if (cmd == "BIENVENUE")
	    pending.push_back(new GreetEvent);
	  if (stream.str().size() > cmd.size())
	    {
	      tmpstream = stream.str().erase(0, cmd.size() + 1);
	      stream.clear();
	      stream.str(tmpstream);
	    }
	  stack.push_back(NetEvent::create(cmd, stream));
	}
    }
  return stack;
}
