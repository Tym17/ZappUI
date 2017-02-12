//
// CircularBuffer.hpp for  in /home/noreply/tek2/unix/zappy/PSU_2015_zappy
//
// Made by Tym17
// Login   <noreply@tym17.com>
//
// Started on  Mon Jun 20 10:29:49 2016 Tym17
// Last update Mon Jun 20 11:41:12 2016 Tym17
//

#ifndef CIRCULARBUFFER_HPP_
# define CIRCULARBUFFER_HPP_

# include <string>

# define CIR_BUFF_SIZE	1024
# define CIRCULAR_BUFF	(CIR_BUFF_SIZE - 1)

class CircularBuffer
{
protected:
  char	internal[CIR_BUFF_SIZE];
  int	readindex;
  int	writeindex;

public:
  CircularBuffer(void);
  CircularBuffer(const CircularBuffer &);
  CircularBuffer &operator=(const CircularBuffer &);
  ~CircularBuffer(void);

  char	&operator[](const int &);
  CircularBuffer &operator<<(const std::string &);

  void	push(const std::string &);
  std::string	extract(char delm = '\n');

  void	incRead(void);
  void	incWrite(void);

  int	getRead(void) const;
  int	getWrite(void) const;
};

#endif /* !CIRCULARBUFFER_HPP_ */
