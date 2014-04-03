//
// main.cpp for main in /home/horiotb/Documents/projets/c++/cpp_nibbler/src-raph
// 
// Made by benjamin horiot
// Login   <horiot_b@epitech.net>
// 
// Started on  Wed Apr  2 12:50:36 2014 benjamin horiot
// Last update Thu Apr  3 14:42:23 2014 benjamin horiot
//

/*
#include "Ncurses.hh"

int		main_moi()
{
  Ncurses	n;
  Snake	s;
  Fruit	f;
  std::pair<int, int>	map;

  map.first = 10;
  map.second = 5;
  n.updateDraw(s, f, map);
  while (1)
    halfdelay(1);
  return (0);
}
*/


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
      std::cout << "aaa" << std::endl;
      nibbler = new Nibbler(handle, map);
      std::cout << "aaa" << std::endl;
      nibbler->runGame();
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      return (-1);
    }
  return (0);
}
