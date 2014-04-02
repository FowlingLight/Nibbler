//
// main.cpp for  in /home/hallelouia/Tek2/C++/cpp_nibbler/src-raph
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Apr  2 10:43:51 2014 Raphael Morand
// Last update Wed Apr  2 12:19:32 2014 Raphael Morand
//

#include	<iostream>

#include	"Nibbler.hh"
#include	"Glibc.hh"
#include	"Snake.hh"
#include	"Fruit.hh"
#include	"IGraphics.hh"

int		main(int ac, char **av)
{
  Nibbler	*nibbler;
  void		*handle;

  if (ac != 4)
    return (0);
  if ((handle = Glibc::Libdl::_dlopen(av[3], RTLD_LAZY)) == NULL)
    {
      std::cout << Glibc::Libdl::_dlerror() << std::endl;
      return (0);
    }
  try
    {
      nibbler = new Nibbler(handle);
      nibbler->runGame();
    }
  catch (std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
}
