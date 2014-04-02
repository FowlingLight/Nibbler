//
// Snake.hh for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Mar 26 13:35:36 2014 Raphael Morand
// Last update Wed Apr  2 15:50:53 2014 benjamin horiot
//

#ifndef		__SNAKE__
#define		__SNAKE__

#include	<utility>
#include	<vector>

typedef		enum
  {
    UP = 0,
    RIGHT,
    DOWN,
    LEFT,
    EXIT
  }		t_directions;

class		Snake;

typedef void	(Snake::*move_ptr)();

class		Snake
{
private :
  int					_size;
  t_directions				_dir;
  std::vector<std::pair<int, int> >	_snake;
  std::pair<int, int>			_head;
  std::pair<int, int>			_tail;
  move_ptr				move_fct[4];
  void					move_up();
  void					move_down();
  void					move_right();
  void					move_left();
public :
  Snake(const std::pair<int, int>& _xyMap);
  ~Snake();
  const std::vector<std::pair<int, int> >&	getSnake() const;
  const std::pair<int, int>&			getHead() const;
  const int					getSize() const;
  const bool			checkCollision(const std::pair<int, int> &_xyMap) const;
  void				addSnake();
  void				moveSnake();
  void				setDir(const t_directions dir);
  const t_directions		getDir() const;
  void				resetTail();
};


#endif
