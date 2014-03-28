/*
** ncurses.cpp for ncurses in /home/horiotb/Documents/projets/c++/nibler/src
** 
** Made by benjamin horiot
** Login   <horiot_b@epitech.net>
** 
** Started on  Wed Mar 19 14:45:03 2014 benjamin horiot
// Last update Fri Mar 28 10:18:14 2014 Raphael Morand
*/

#include "anibbler.hh"

NCurses::NCurses(char *name)
{
  // /usr/lib/libncurses.so.5
  _handler = dlopen(name, RTLD_LAZY);
  if (_handler)
    {
      _initscr = (window_ptr)dlsym(_handler, "initscr");
      _erase = (int_ptr)dlsym(_handler, "erase");
      _printw = (int_ptr_mod)dlsym(_handler, "mvprintw");
      _endwin = (int_ptr)dlsym(_handler, "endwin");
      _getch = (int_ptr)dlsym(_handler, "getch");
      if (!_initscr || !_erase || !_printw || !_endwin || !_getch)
	std::exit(-1);
    }
  else
    {
      my_puterror("Couldn't open the lib", 0);
      std::exit(-1);
    }
}

NCurses::~NCurses()
{
  dlclose(_handler);
}

int		NCurses::checkEatenTail(Snake *s)
{
  // does'nt work if no tail
  std::vector<int>	tailX = s->getTailX();
  std::vector<int>	tailY = s->getTailY();
  int		i = 0;

  while (tailX[i])
    if (tailX[i] == s->getHeadX() && tailY[i++] == s->getHeadY())
      return (-1);
  return (0);
}

void		NCurses::modifHead(Snake *s)
{
  int		dir = s->getDir();

  if (dir % 2)
    {
      if (dir == 1)
	s->setHead(s->getHeadX(), s->getHeadY() - 1);
      else
        s->setHead(s->getHeadX(), s->getHeadY() + 1);
    }
  else
    {
      if (dir == 0)
        s->setHead(s->getHeadX() - 1, s->getHeadY());
      else
        s->setHead(s->getHeadX() + 1, s->getHeadY());
    }
}

void		NCurses::affSnake(Snake *s, int width, int height)
{
  int		i = 0;
  std::vector<int>	tailX = s->getTailX();
  std::vector<int>	tailY = s->getTailY();

  while (i < width)
    {
      _printw(i, 0, "#");
      _printw(i, height, "#");
      ++i;
    }
  i = 0;
  while (i < height)
    {
      _printw(width, i, "#");
      ++i;
    }
  i = 0;
  // doesn't work if no tail
  //  while (tailX[i])
  //  _printw(tailX[i], tailY[i++], "X");
  _printw(s->getHeadX(), s->getHeadY(), "x");
}

void		NCurses::game(int width, int height)
{
  bool		fail = true;
  int		input;
  Snake		s(width / 2, height / 2);

  initscr();
  while (fail)
    {
      erase(); 
      move(0, 0);
      affSnake(&s, width, height);
      input = getch();
      // key up/down what is EXIT_KEY
      if (input == KEY_LEFT)
	s.setDir(false);
      else if (input == KEY_RIGHT)
	s.setDir(true);
      else if (input == KEY_EXIT)
	std::exit(0);
      //      std::cout << (char)input << std::endl;
      //      s.addTailX(s.getHeadX());
      //s.addTailY(s.getHeadY());
      modifHead(&s);
      //if (checkEatenTail(&s))
      //fail = false;
      refresh();
    }
  endwin();
}
