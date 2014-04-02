//
// main.cpp for main in /home/horiotb/Documents/projets/c++/cpp_nibbler/src-raph
// 
// Made by benjamin horiot
// Login   <horiot_b@epitech.net>
// 
// Started on  Wed Apr  2 12:50:36 2014 benjamin horiot
// Last update Wed Apr  2 16:04:24 2014 benjamin horiot
//

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
