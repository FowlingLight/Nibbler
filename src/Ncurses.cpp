//
// Ncurses.cpp for Ncurses in /home/horiotb/Documents/projets/c++/cpp_nibbler/src-raph
// 
// Made by benjamin horiot
// Login   <horiot_b@epitech.net>
// 
// Started on  Wed Apr  2 10:04:48 2014 benjamin horiot
// Last update Sun Apr  6 20:56:53 2014 benjamin horiot
//

#include <iostream>

#include "Ncurses.hh"

Ncurses::Ncurses()
{
  int		mod;

  mod = Glibc::Fcntl::_fcntl(0, F_GETFL, 0);
  mod |= O_NONBLOCK;
  Glibc::Fcntl::_fcntl(0, F_SETFL, mod);
  w = initscr();
  noecho();
  curs_set(0);
  raw();
}

Ncurses::~Ncurses()
{
  int		mod;

  noraw();
  curs_set(1);
  echo();
  endwin();
  mod = Glibc::Fcntl::_fcntl(0, F_GETFL, 0);
  mod &= ~O_NONBLOCK;
  Glibc::Fcntl::_fcntl(0, F_SETFL, mod);
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

t_directions	Ncurses::getInput(const t_directions dir)
{
  char		c;

  Glibc::Usleep::_usleep(200000);
  if (Glibc::Read::_read(0, &c, 1) != -1)
    {
      if (c == 27)
	{
	  if (Glibc::Read::_read(0, &c, 1) != -1)
	    {
	      if (Glibc::Read::_read(0, &c, 1) != -1)
		{
		  if (c == 'D')
		    {
		      if (dir == 0)
			return ((t_directions)3);
		      return ((t_directions)((int)dir - 1));
		    }
		  else if (c == 'C')
		    {
		      if (dir == 3)
			return ((t_directions)0);
		      return ((t_directions)((int)dir + 1));
		    }
		}
	    }
	  return ((t_directions)4);
	}
      std::cout << (int)c << std::endl;
    }
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
  mvprintw(mapSize.second + 1, mapSize.first + 1, "#");
  attroff(COLOR_PAIR(21));
  init_pair(22, COLOR_GREEN, -1);
  attron(COLOR_PAIR(22));
  a = 0;
  while (a < (int)snake.size())
    {
      mvprintw(snake[a].second, snake[a].first, "+");
      a++;
    }
  mvprintw(s.getHead().second, s.getHead().first, "x");
  attroff(COLOR_PAIR(22));
  init_pair(23, COLOR_BLUE, -1);
  attron(COLOR_PAIR(23));
  mvprintw(f.getFruit().second, f.getFruit().first, "o");
  attroff(COLOR_PAIR(23));
  refresh();
}
