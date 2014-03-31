//
// Glibc.cpp for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Fri Mar 28 16:43:36 2014 Raphael Morand
// Last update Fri Mar 28 16:47:19 2014 Raphael Morand
//

#include	"Glibc.hh"

long int	Glibc::Random::_random()
{return (random());}

void	Glibc::Random::_srandom(unsigned int seed)
{srandom(seed);}

time_t	Glibc::Time::_time()
{return (time());}
