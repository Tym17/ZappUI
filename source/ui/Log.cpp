//
// Log.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Tue Jun 14 14:18:57 2016 Tym17
// Last update Sat Jun 25 14:05:28 2016 Tym17
//

#include <iostream>
#include "Log.hpp"

Log::Log(const std::string &n, const std::string &h, bool eout) :
  active(true), name(n), header(h), errOut(eout)
{
  Log *toDelete = NULL;

  try
    {
      toDelete = instances.at(n);
    }
  catch (std::exception &e)
    {
      (void) e;
    }
  instances[n] = this;
  if (toDelete != NULL)
    delete toDelete;
}

Log &Log::operator=(const Log &o)
{
  header = o.header;
  errOut = o.errOut;
  return *this;
}

Log::~Log(void)
{
  instances.erase(name);
}

void	Log::disable(void)
{
  active = false;
  return ;
}

void	Log::enable(void)
{
  active = true;
  return ;
}

bool	Log::isActive(void) const
{
  return active;
}

void	Log::log(const std::string &msg) const
{
  if (errOut)
    std::cerr << header << " " << msg << std::endl;
  else
    std::cout << header << " " << msg << std::endl;
  return ;
}

void	Log::in(const std::string &logger, const std::string &msg)
{
  try
    {
      instances.at(logger);
    }
  catch (std::exception &e)
    {
      (void) e;
    }
  instances[logger]->log(msg);
  return ;
}

std::map<std::string, Log *>	Log::instances;
