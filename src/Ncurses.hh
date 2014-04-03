//
// Ncurses.hh for Ncurses in /home/horiotb/Documents/projets/c++/cpp_nibbler/src-raph
// 
// Made by benjamin horiot
// Login   <horiot_b@epitech.net>
// 
// Started on  Wed Apr  2 10:05:42 2014 benjamin horiot
// Last update Thu Apr  3 16:46:15 2014 benjamin horiot
//

#ifndef NCURSES_HH_
# define NCURSES_HH_

//# include <iostream>
# include <curses.h>
//# include <utility>

# include "IGraphics.hh"

class		Ncurses : public IGraphics
{
  WINDOW	*w;

public:
  Ncurses();
  virtual ~Ncurses();

  virtual t_directions	getInput(const t_directions) const;
  virtual void		updateDraw(const Snake &, const Fruit &, const std::pair<int, int>&);
  virtual void		gameOver(const bool);
};

extern "C"
{
Ncurses		*getInstance(const std::pair<int, int>& map);

void		deleteInstance(Ncurses *);
}
#endif /* !NCURSES_HH_ */