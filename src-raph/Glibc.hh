//
// Glibc.hh for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Fri Mar 28 16:41:23 2014 Raphael Morand
// Last update Tue Apr  1 09:47:53 2014 Raphael Morand
//

#ifndef		__GLIBC_HH_
#define		__GLIBC_HH_

#include	<time.h>
#include	<stdlib.h>

namespace	Glibc
{
  class		Random
  {
  public :
    static long int	_random();
    static void	_srandom(unsigned int seed);
  };

  class		Time
  {
  public:
    static time_t	_time(time_t *);
  };
}

#endif
