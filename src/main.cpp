//
// main.cpp for main in /home/horiotb/Documents/projets/c++/cpp_nibbler/src-raph
// 
// Made by benjamin horiot
// Login   <horiot_b@epitech.net>
// 
// Started on  Wed Apr  2 12:50:36 2014 benjamin horiot
// Last update Sun Apr  6 16:44:53 2014 Raphael Morand
//

#include	<iostream>

#include	"Nibbler.hh"
#include	"Glibc.hh"
#include	"Snake.hh"
#include	"Fruit.hh"
#include	"IGraphics.hh"

bool		check_size(int x, int y)
{
  if (x >= 10 && x <= 55 && y >= 10 && y <= 55)
    return (true);
  return (false);
}

int		main(int ac, char **av)
{
  Nibbler	*nibbler;
  void		*handle;
  std::pair<int, int>	map;

  if (ac != 4)
    {
      std::cerr << "Usage : ./nibler width[10..55] height[10..55] ./LIB.so" << std::endl;
      return (-1);
    }
  if ((handle = Glibc::Libdl::_dlopen(av[3], RTLD_LAZY)) == NULL)
    {
      std::cerr << Glibc::Libdl::_dlerror() << std::endl;
      return (-1);
    }
  if (!check_size(Glibc::Atoi::_atoi(av[1]), Glibc::Atoi::_atoi(av[2])))
    {
      std::cerr << "Entrer a size between 10x10 and 55x55" << std::endl;
      return (-1);
    }
  try
    {
      map.first = Glibc::Atoi::_atoi(av[1]);
      map.second = Glibc::Atoi::_atoi(av[2]);
      nibbler = new Nibbler(handle, map);
      nibbler->runGame();
      std::cout << "Game Over" << std::endl;
      delete nibbler;
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      return (-1);
    }
  return (0);
}
