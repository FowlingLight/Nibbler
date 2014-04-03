//
// Nibbler.cpp for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Mar 26 13:04:56 2014 Raphael Morand
// Last update Thu Apr  3 11:04:23 2014 Raphael Morand
//

#include	<exception>

#include	"Nibbler.hh"

Nibbler::Nibbler(void *handler, const std::pair<int, int>& xyMap)
{
  _xyMap.first = xyMap.first;
  _xyMap.second = xyMap.second;
  _snake = new Snake(_xyMap);
  _fruit = new Fruit(0, 0);
  get = (getInstance)Glibc::Libdl::_dlsym(handler, "getInstance");
  del = (deleteInstance)Glibc::Libdl::_dlsym(handler, "deleteInstance");
  if (!get || !del || !_snake || !_fruit)
    throw std::exception();
  _fruit->moveFruit(_snake, _xyMap);
  _graphics = get(_xyMap);
  _graphics->updateDraw(*snake, *_fruit, _xyMap);
}

Nibbler::Nibbler(void *handler)
{
  _xyMap.first = 20;
  _xyMap.second = 10;
  _snake = new Snake(_xyMap);
  _fruit = new Fruit(0, 0);
  get = (getInstance)Glibc::Libdl::_dlsym(handler, "getInstance");
  del = (deleteInstance)Glibc::Libdl::_dlsym(handler, "deleteInstance");
  if (!get || !del || !_snake || !_fruit)
    throw std::exception();
  _fruit->moveFruit(_snake, _xyMap);
  _graphics = get();
  _graphics->updateDraw(*snake, *_fruit, _xyMap);
}

Nibbler::~Nibbler()
{
  del(_graphics);
  delete _snake;
  delete _fruit;
}

bool		Nibbler::runGame()
{
  t_directions	tmp;
  bool		victory = false;
  struct timeval	t;
  struct timeval	tmp_t;

  while (!_snake->checkCollision(_xyMap) && !victory)
    {
      tmp = _snake->getDir();
      Glibc::Time::_gettimeofday(&t, NULL);
      tmp_t = t;
      while (tmp_t.tv_usec < t.tv_usec + 500000)
	{
	  tmp = _graphics->getInput(_snake->getDir());
	  Glibc::Time::_gettimeofday(&tmp_t, NULL);
	}
      _snake->setDir(tmp);
      _snake->moveSnake();
      if (_fruit->isEaten(_snake->getHead()))
	{
	  _snake->addSnake();
	  if (_snake->getSize() != _xyMap.first * _xyMap.second)
	    _fruit->moveFruit(_snake, _xyMap);
	  else
	    victory = true;
	}
      _graphics->updateDraw(*_snake, *_fruit, _xyMap);
    }
  return (victory);
}
