/*
** ncurses.cpp for ncurses in /home/horiotb/Documents/projets/c++/nibler/src
** 
** Made by benjamin horiot
** Login   <horiot_b@epitech.net>
** 
** Started on  Wed Mar 19 14:45:03 2014 benjamin horiot
** Last update Fri Mar 21 10:02:52 2014 benjamin horiot
*/

#include "nibbler.hh"

NCurses::NCurses(char *name)
{
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
      _printw(i++, height, "#");
    }
  i = 0;
  while (i < height)
    {
      _printw(0, i, "#");
      _printw(width, i++, "#");
    }
  i = 0;
  while (tailX[i])
    _printw(tailX[i], tailY[i++], "X");
  _printw(s->getHeadX(), s->getHeadY(), "x");
}

void		NCurses::game(int width, int height)
{
  bool		fail = true;
  int		input;
  Snake		s(width / 2, height / 2);

  initscr();
  std::cout << "a" << std::endl;
  while (fail)
    {
      std::cout << "b" << std::endl;
      erase(); 
      std::cout << "c" << std::endl;
      move(0, 0);
      std::cout << "d" << std::endl;
      input = getch();
      std::cout << "e" << std::endl;
      if (input == KEY_LEFT)
	s.setDir(false);
      else if (input == KEY_RIGHT)
	s.setDir(true);
      else if (input == KEY_EXIT)
	std::exit(0);
      std::cout << input << std::endl;
      std::cout << "f" << std::endl;
      s.addTailX(s.getHeadX());
      s.addTailY(s.getHeadY());
      std::cout << "g" << std::endl;
      modifHead(&s);
      std::cout << "h" << std::endl;
      if (checkEatenTail(&s))
	std::cout << "1" << std::endl;
	fail = false;
      std::cout << "i" << std::endl;
      affSnake(&s, width, height);
      std::cout << "j" << std::endl;
      refresh();
      std::cout << "k" << std::endl;
    }
  endwin();
}
