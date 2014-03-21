/*
** nibler.hh for nibler in /home/horiotb/Documents/projets/c++/nibler/src
** 
** Made by benjamin horiot
** Login   <horiot_b@epitech.net>
** 
** Started on  Wed Mar 19 11:34:02 2014 benjamin horiot
** Last update Fri Mar 21 10:03:13 2014 benjamin horiot
*/

#ifndef NIBBLER_HH_
# define NIBBLER_HH_

# include <iostream>
# include <cstring>
# include <dlfcn.h>
# include <cerrno>
# include <ncurses.h>
# include <vector>
# include <sstream>
# include <cstdlib>

typedef	int (*int_ptr)();
typedef	int (*int_ptr_mod)(int, int, const char *, ...);
typedef	WINDOW *(*window_ptr)();

class			Snake
{
  int			_head[2];
  std::vector<int>	_tailx;
  std::vector<int>	_taily;
  int			_dir;

public:
  Snake(int, int);
  ~Snake() {};

  int		getHeadX() const;
  int		getHeadY() const;
  void		setHead(int, int);
  std::vector<int>	getTailX() const;
  void		addTailX(int);
  std::vector<int>	getTailY() const;
  void		addTailY(int);
  int		getDir() const;
  void		setDir(bool);
};

class		NCurses
{
  void		*_handler;
  window_ptr	_initscr;
  int_ptr_mod	_printw;
  int_ptr	_getch;
  int_ptr	_erase;
  int_ptr	_refresh;
  int_ptr	_endwin;

public:
  NCurses(char *);
  ~NCurses();

  int		checkEatenTail(Snake *);
  void		modifHead(Snake *);
  void		affSnake(Snake *, int, int);
  void		game(int, int);
};

/* error.cpp */
int		my_puterror(std::string, int);
int		my_fcterror(char *, int);
int		my_errno(char *, int);

/* main.cpp */
int		my_putusage();
int		check_size(int, int);
int		check_lib(char *);
int		main(int, char **);


#endif /* !NIBBLER_HH_ */
