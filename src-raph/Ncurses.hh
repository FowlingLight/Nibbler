//
// Ncurses.hh for Ncurses in /home/horiotb/Documents/projets/c++/cpp_nibbler/src-raph
// 
// Made by benjamin horiot
// Login   <horiot_b@epitech.net>
// 
// Started on  Wed Apr  2 10:05:42 2014 benjamin horiot
// Last update Wed Apr  2 16:03:14 2014 benjamin horiot
//

#ifndef NCURSES_HH_
# define NCURSES_HH_

#include <iostream>
#include <curses.h>
#include <utility>
# include "IGraphics.hh"

class		Ncurses : public IGraphics
{

public:
  Ncurses();
  ~Ncurses();

  t_directions	getInput(const t_directions);
  void		updateDraw(const Snake &, const Fruit &, const std::pair<int, int>);
  void		gameOver();//const bool);
};

#endif /* !NCURSES_HH_ */
