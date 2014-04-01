//
// Glibc.cpp for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Fri Mar 28 16:43:36 2014 Raphael Morand
// Last update Tue Apr  1 10:02:27 2014 Raphael Morand
//

#include	"Glibc.hh"

long int	Glibc::Random::_random()
{return (random());}

void	Glibc::Random::_srandom(unsigned int seed)
{srandom(seed);}

time_t	Glibc::Time::_time(time_t *t)
{return (time(t));}

void	*Glibc::Libdl::_dlopen(const char *filename, int flag)
{
  return (dlopen(filename, flag));
}

char	*Glibc::Libdl::_dlerror(void)
{
  return (dlerror());
}

void	*Glibc::Libdl::_dlsym(void *handle, const char *symbol)
{
  return (dlsym(handle, symbol));
}

int	Glibc::Libdl::_dlclose(void *handle)
{
  return (dlclose(handle));
}
