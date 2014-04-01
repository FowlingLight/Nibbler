//
// Fruit.cpp for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Thu Mar 27 17:21:04 2014 Raphael Morand
// Last update Tue Apr  1 09:53:39 2014 Raphael Morand
//

#include	"Fruit.hh"

Fruit::Fruit(const int x, const int y)
{
  _pos.first = x;
  _pos.second = y;
  Glibc::Random::_srandom(Glibc::Time::_time(NULL));
}

Fruit::~Fruit()
{}

const std::pair<int, int>&	Fruit::getFruit() const
{return (_pos);}

const bool			Fruit::isEaten(const std::pair<int, int>& SnakeHead) const
{
  if (SnakeHead.first == _pos.first &&
      SnakeHead.second == _pos.second)
    return (true);
  return (false);
}

void				Fruit::moveFruit(const Snake& snake, 
						 const std::pair<int, int>& xyMap)
{
  int				x;
  int				y;
  int				i;
  bool				is_pos_ok = false;

  while (!is_pos_ok)
    {
      x = Glibc::Random::_random() % xyMap.first + 1;
      y = Glibc::Random::_random() % xyMap.second + 1;
      is_pos_ok = true;
      i = 0;
      while (i < snake.getSnake().size())
	{
	  if (x == snake.getSnake()[i].first && y == snake.getSnake()[i].second)
	    is_pos_ok = true;
	  ++i;
	}
    }
  _pos.first = x;
  _pos.second = y;
}
