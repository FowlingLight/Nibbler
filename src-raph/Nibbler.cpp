//
// Nibbler.cpp for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Mar 26 13:04:56 2014 Raphael Morand
// Last update Tue Apr  1 12:54:18 2014 Raphael Morand
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
  _graphics = get();
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

  while (!_snake->checkCollision(_xyMap) && !victory)
    {
      tmp = _snake->getDir();
      while (/*time managing*/1)
	{
	  tmp = _graphics->getInput(_snake->getDir());
	}
      _snake->setDir(tmp);
      _snake->moveSnake();
      if (_fruit->isEaten(_snake->getHead()))
	{
	  _snake->addSnake();
	  if (_snake->getSize() != _xyMap.first * _xyMap.second)
	    _fruit->moveFruit(_snake, _xyMap);
	  else
	    {
	      victory = true;
	      delete _fruit;
	    }
	}
      _graphics->updateDraw(*_snake, *_fruit, _xyMap);
    }
  return (victory);
}
