//
// Ncurses.cpp for Ncurses in /home/horiotb/Documents/projets/c++/cpp_nibbler/src-raph
// 
// Made by benjamin horiot
// Login   <horiot_b@epitech.net>
// 
// Started on  Wed Apr  2 10:04:48 2014 benjamin horiot
// Last update Wed Apr  2 16:02:30 2014 benjamin horiot
//

#include "Ncurses.hh"

Ncurses::Ncurses()
{
  initscr();
  noecho();
  raw();
}

Ncurses::~Ncurses()
{
  endwin();
}

t_directions	getInput(const t_directions dir)
{
  unsigned int	a = getch();

  if (a == KEY_LEFT)
    {
      if (dir == 0)
	return (3);
      return (dir - 1);
    }
  else if (a == KEY_RIGHT)
    {
      if (dir == 3)
	return (0);
      return (dir + 1);
    }
  else if (a == ESC)
    return (4);
  return (-1);
}

void		Ncurses::updateDraw(const Snake &s, const Fruit &f, const std::pair<int, int> mapSize)
{
  int		a;
  std::vector<std::pair<int, int> >	snake = s.getSnake();

  use_default_colors();
  erase();
  curs_set(0);
  start_color();
  init_pair(21, COLOR_RED, -1);
  attron(COLOR_PAIR(21));
  a = 0;
  while (a <= mapSize.first)
    {
      mvprintw(0, a, "+");
      mvprintw(mapSize.second, a++, "+");
    }
  a = 0;
  while (a <= mapSize.second)
    {
      mvprintw(a, 0, "+");
      mvprintw(a++, mapSize.first, "+");
    }
  attroff(COLOR_PAIR(21));
  init_pair(22, COLOR_GREEN, -1);
  attron(COLOR_PAIR(22));
  a = 0;
  mvprintw(s.getHead().second, s.getHead().first, "X");
  while (snake[a])
    {
      mvprintw(snake[a].second, snake[a].first, "x");
      a++;
    }
  attroff(COLOR_PAIR(22));
  init_pair(23, COLOR_BLUE, -1);
  attron(COLOR_PAIR(23));
  mvprintw(f.getFruit().second, f.getFruit().first, "8");
  attroff(COLOR_PAIR(23));
  refresh();
}

void		gameOver()//const bool lose)
{

}
