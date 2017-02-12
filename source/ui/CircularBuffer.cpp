//
// CircularBuffer.cpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Mon Jun 20 10:37:42 2016 Tym17
// Last update Thu Jun 23 22:53:38 2016 Tym17
//

#include <iostream>
#include "CircularBuffer.hpp"

CircularBuffer::CircularBuffer(void) :
  readindex(0), writeindex(0)
{
  int	i = -1;

  while (++i != CIRCULAR_BUFF)
    internal[i] = 0;
}

CircularBuffer::CircularBuffer(const CircularBuffer &o) :
  readindex(o.readindex), writeindex(o.writeindex)
{
  int	i = -1;

  while (++i != CIRCULAR_BUFF)
    internal[i] = o.internal[i];
}

CircularBuffer &CircularBuffer::operator=(const CircularBuffer &o)
{
  readindex = o.readindex;
  writeindex = o.writeindex;

  int	i = -1;
  while (++i != CIRCULAR_BUFF)
    internal[i] = o.internal[i];
  return *this;
}

CircularBuffer::~CircularBuffer(void)
{
}

char &CircularBuffer::operator[](const int &i)
{
  return internal[i % CIRCULAR_BUFF];
}

CircularBuffer &CircularBuffer::operator<<(const std::string &o)
{
  push(o);
  return *this;
}

void	CircularBuffer::push(const std::string &str)
{
  for (std::string::const_iterator it = str.begin();
       it != str.end(); it++)
    {
      internal[writeindex] = *it;
      writeindex = (writeindex + 1) % CIRCULAR_BUFF;
    }
  return ;
}

std::string	CircularBuffer::extract(char dlm)
{
  std::string	ret;
  int	i = readindex;

  while (internal[i] != dlm && i != writeindex)
    {
      ret.push_back(internal[i]);
      i = (i + 1) % CIRCULAR_BUFF;
    }
  if (internal[i] == dlm)
    {
      readindex = i;
      internal[i] = '\0';
      if (i != writeindex)
	readindex = (i + 1) % CIRCULAR_BUFF;
    }
  else
    ret.push_back('\n');
  return ret;
}

void	CircularBuffer::incRead(void)
{
  readindex = (readindex + 1) % CIRCULAR_BUFF;
  return ;
}

void	CircularBuffer::incWrite(void)
{
  writeindex = (writeindex + 1) % CIRCULAR_BUFF;
  return ;
}

int	CircularBuffer::getRead(void) const
{
  return readindex;
}

int	CircularBuffer::getWrite(void) const
{
  return writeindex;
}
