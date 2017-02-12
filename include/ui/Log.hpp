//
// Log.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Tue Jun 14 14:13:44 2016 Tym17
// Last update Tue Jun 14 14:56:05 2016 Tym17
//

#ifndef LOG_HPP_
# define LOG_HPP_

# include <map>
# include <string>

class Log
{
  bool	active;
  std::string name;
  std::string header;
  bool	errOut;

  static std::map<std::string, Log *>	instances;

public:
  Log(const std::string &name, const std::string &header, bool);
  ~Log(void);
  Log &operator=(const Log &);

  void	disable(void);
  void	enable(void);
  bool	isActive(void) const;
  void	log(const std::string &msg) const;

  static void	in(const std::string &logger, const std::string &msg);
};

#endif /* !LOG_HPP_ */
