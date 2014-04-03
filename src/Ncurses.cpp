//
// Ncurses.cpp for Ncurses in /home/horiotb/Documents/projets/c++/cpp_nibbler/src-raph
// 
// Made by benjamin horiot
// Login   <horiot_b@epitech.net>
// 
// Started on  Wed Apr  2 10:04:48 2014 benjamin horiot
// Last update Thu Apr  3 17:03:04 2014 benjamin horiot
//

#include <iostream>
#include "Ncurses.hh"

Ncurses::Ncurses()
{
  w = initscr();
  noecho();
  //raw();
}

Ncurses::~Ncurses()
{
  echo();
  endwin();
  system("clear");
}

extern "C" 
{
  Ncurses	*getInstance(const std::pair<int, int> &map)
  {
    (void)map;
    return (new Ncurses);
  }

  void		deleteInstance(Ncurses *n)
  {
    delete (n);
  }
}

t_directions	Ncurses::getInput(const t_directions dir) const
{
  //nodelay(w, 1);
  halfdelay(1);
  unsigned int	a = getch();
  //usleep(100000);
  //std::cout << a << std::endl;
  if (a == 113)
    {
      if (dir == 0)
	return ((t_directions)3);
      return ((t_directions)((int)dir - 1));
    }
  else if (a == 100)
    {
      if (dir == 3)
	return ((t_directions)0);
      return ((t_directions)((int)dir + 1));
    }
  else if (a == 27)
    return ((t_directions)4);
  return (dir);
}

void		Ncurses::updateDraw(const Snake &s, const Fruit &f,
				    const std::pair<int, int>& mapSize)
{
  int		a;
  std::vector<std::pair<int, int> >	snake = s.getSnake();

  use_default_colors();
  erase();
  start_color();
  init_pair(21, COLOR_RED, -1);
  attron(COLOR_PAIR(21));
  a = 0;
  while (a <= mapSize.first)
    {
      mvprintw(0, a, "#");
      mvprintw(mapSize.second + 1, a++, "#");
    }
  a = 0;
  while (a <= mapSize.second)
    {
      mvprintw(a, 0, "#");
      mvprintw(a++, mapSize.first + 1, "#");
    }
  attroff(COLOR_PAIR(21));
  init_pair(22, COLOR_GREEN, -1);
  attron(COLOR_PAIR(22));
  a = 0;
  while (a < snake.size())
    {
      std::cout << "tail ";
      mvprintw(snake[a].second, snake[a].first, "+");
      a++;
    }
  std::cout << std::endl;
  mvprintw(s.getHead().second, s.getHead().first, "x");
  attroff(COLOR_PAIR(22));
  init_pair(23, COLOR_BLUE, -1);
  attron(COLOR_PAIR(23));
  mvprintw(f.getFruit().second, f.getFruit().first, "o");
  attroff(COLOR_PAIR(23));
  refresh();
}

void		Ncurses::gameOver(const bool lose)
{
  (void)lose;
}