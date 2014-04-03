//
// Snake.cpp for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Mar 26 14:56:48 2014 Raphael Morand
// Last update Tue Apr  1 11:15:25 2014 Raphael Morand
//

#include		"Snake.hh"

Snake::Snake(const std::pair<int, int>& _xyMap)
{
  int		i = 1;

  _size = 4;
  _dir = UP;
  _snake.push_back(std::pair<int, int>(_xyMap.first / 2, _xyMap.second / 2));
  while (i < _size)
    {
      _snake.push_back(std::pair<int, int>(_snake[i - 1].first, _snake[i - 1].second + 1));
      ++i;
    }
  _head = _snake[0];
  _tail = _snake[3];
  move_fct[0] = &Snake::move_up;
  move_fct[1] = &Snake::move_right;
  move_fct[2] = &Snake::move_down;
  move_fct[3] = &Snake::move_left;
}

Snake::~Snake()
{}

const std::vector<std::pair<int, int> >&	Snake::getSnake() const
{return (_snake);}

const std::pair<int, int>&	Snake::getHead() const
{return (_head);}

const int		Snake::getSize() const
{return (_size);}

const bool		Snake::checkCollision(const std::pair<int, int>& map) const
{
  int		i = 1;

  if (_head.first == 0 || _head.first == map.first + 1)
    return (true);
  if (_head.second == 0 || _head.second == map.second + 1)
    return (true);
  while (i != _size)
    {
      if (_head == _snake[i])
	return (true);
      ++i;
    }
  return (false);
}		

void			Snake::addSnake()
{
  _snake.push_back(_tail);
  ++_size;
}

void			Snake::resetTail()
{_tail = _snake.back();}

void			Snake::move_up()
{
  int			i = 1;

  while (i < _size)
    {
      _snake[i] = _snake[i - 1];
      ++i;
    }
  _snake[0].second--;
  _head = _snake[0];
}

void			Snake::move_down()
{
  int			i = 1;

  while (i < _size)
    {
      _snake[i] = _snake[i - 1];
      ++i;
    }
  _snake[0].second++;
  _head = _snake[0];
}

void			Snake::move_right()
{
  int			i = 1;

  while (i < _size)
    {
      _snake[i] = _snake[i - 1];
      ++i;
    }
  _snake[0].first++;
  _head = _snake[0];
}

void			Snake::move_left()
{
  int			i = 1;

  while (i < _size)
    {
      _snake[i] = _snake[i - 1];
      ++i;
    }
  _snake[0].first--;
  _head = _snake[0];
}

void			Snake::moveSnake()
{(this->*move_fct[_dir])();}

void			Snake::setDir(const t_directions dir)
{_dir = dir;}

const t_directions	Snake::getDir() const
{return (_dir);}
