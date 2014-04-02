//
// main.cpp for main in /home/horiotb/Documents/projets/c++/cpp_nibbler/src-raph
// 
// Made by benjamin horiot
// Login   <horiot_b@epitech.net>
// 
// Started on  Wed Apr  2 12:50:36 2014 benjamin horiot
// Last update Wed Apr  2 13:49:08 2014 benjamin horiot
//

#include "Ncurses.hh"

int		main()
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
