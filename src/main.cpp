//
// main.cpp for main in /home/horiotb/Documents/projets/c++/cpp_nibbler/src-raph
// 
// Made by benjamin horiot
// Login   <horiot_b@epitech.net>
// 
// Started on  Wed Apr  2 12:50:36 2014 benjamin horiot
// Last update Fri Apr  4 10:36:35 2014 benjamin horiot
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
  std::pair<int, int>	map;

  if (ac != 4)
    {
      std::cerr << "Usage : ./nibler width height LIB.so" << std::endl;
      return (-1);
    }
  if ((handle = Glibc::Libdl::_dlopen(av[3], RTLD_LAZY)) == NULL)
    {
      std::cerr << Glibc::Libdl::_dlerror() << std::endl;
      return (-1);
    }
  try
    {
      map.first = Glibc::Atoi::_atoi(av[1]);
      map.second = Glibc::Atoi::_atoi(av[2]);
      nibbler = new Nibbler(handle, map);
      nibbler->runGame();
      delete nibbler;
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      return (-1);
    }
  return (0);
}
