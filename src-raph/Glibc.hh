//
// Glibc.hh for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Fri Mar 28 16:41:23 2014 Raphael Morand
// Last update Wed Apr  2 11:11:45 2014 Raphael Morand
//

#ifndef		__GLIBC_HH_
#define		__GLIBC_HH_

#include	<time.h>
#include	<sys/time.h>
#include	<stdlib.h>
#include	<dlfcn.h>

namespace	Glibc
{
  class		Atoi
  {
  public:
    static int	_atoi(const char* number);
  };

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
    static int		_gettimeofday(struct timeval *t, struct timezone *tzp);
  };

  class		Libdl
  {
  public:
    static void	*_dlopen(const char *filename, int flag);
    static char *_dlerror(void);
    static void *_dlsym(void *handle, const char *symbol);
    static int	_dlclose(void *handle);
  };
}

#endif
