//
// CNetException.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Wed Jun 15 11:38:06 2016 Tym17
// Last update Sun Jun 26 21:38:58 2016 Tym17
//

#ifndef CNETEXCEPTION_HPP_
# define CNETEXCEPTION_HPP_

# include <exception>
# define ERR_CODE	-1

class CNetException //: public std::exception
{
public:
  CNetException(void) {}
  CNetException(const CNetException &o)
  { (void)o; }
  virtual ~CNetException(void) throw() {}
  virtual const char *what(void) const throw()
  { return "CNet: An error occured"; }
};

class FdError : public std::exception
{
public:
  FdError(void) {}
  FdError(const FdError &o)
  { (void)o; }
  virtual ~FdError(void) throw() {}
  virtual const char *what(void) const throw()
  { return "CNet: Could not close Fd."; }
};

class FdSock : public std::exception
{
public:
  FdSock(void) {}
  FdSock(const FdSock &o)
  { (void)o; }
  virtual ~FdSock(void) throw() {}
  virtual const char *what(void) const throw()
  { return "CNet: Could not create socket fd."; }
};

class ConnectError : public std::exception
{
public:
  ConnectError(void) {}
  ConnectError(const ConnectError &o)
  { (void)o; }
  virtual ~ConnectError(void) throw() {}
  virtual const char *what(void) const throw()
  { return "CNet: Could not connect."; }
};

class SocketError : public std::exception
{
public:
  SocketError(void) {}
  SocketError(const SocketError &o)
  { (void)o; }
  virtual ~SocketError(void) throw() {}
  virtual const char *what(void) const throw()
  { return "CNet: Could not create socket fd."; }
};

class ReadError : public std::exception
{
public:
  ReadError(void) {}
  ReadError(const ReadError &o)
  { (void)o; }
  virtual ~ReadError(void) throw() {}
  virtual const char *what(void) const throw()
  { return "CNet: Could not read on fd."; }
};

class WriteError : public std::exception
{
public:
  WriteError(void) {}
  WriteError(const WriteError &o)
  { (void)o; }
  virtual ~WriteError(void) throw() {}
  virtual const char *what(void) const throw()
  { return "CNet: Could not write on fd."; }
};

#endif /* !CNETEXCEPTION_HPP_ */
