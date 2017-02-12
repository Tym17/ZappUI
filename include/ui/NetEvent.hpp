//
// NetEvent.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Tue Jun 14 17:50:31 2016 Tym17
// Last update Thu Jun 23 10:00:51 2016 Tym17
//

#ifndef NETEVENT_HPP_
# define NETEVENT_HPP_

# include <string>
# include <sstream>

class NetEvent
{
protected:
  std::string	cmd;
  int		idx;

  static NetEvent *cr_map(const std::string &, std::stringstream &);
  static NetEvent *cr_pl(const std::string &, std::stringstream &);
  static NetEvent *cr_egg(const std::string &, std::stringstream &);

public:
  NetEvent(void);
  NetEvent(const NetEvent &);
  NetEvent &operator=(const NetEvent &);
  virtual ~NetEvent(void);

  const char	*c_str(void) const;
  void	inc(int);
  bool	isDone(void) const;

  static NetEvent *create(const std::string &, std::stringstream &);
};

#endif /* !NETEVENT_HPP_ */
