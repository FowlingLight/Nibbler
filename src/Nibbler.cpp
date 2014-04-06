//
// Nibbler.cpp for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Mar 26 13:04:56 2014 Raphael Morand
// Last update Sun Apr  6 12:49:24 2014 Raphael Morand
//

#include	<exception>
#include	<iostream>

#include	"Nibbler.hh"

Nibbler::Nibbler(void *handler, const std::pair<int, int>& xyMap)
{
  _xyMap.first = xyMap.first;
  _xyMap.second = xyMap.second;
  _snake = new Snake(_xyMap);
  _fruit = new Fruit(0, 0);
  get = (getInst)Glibc::Libdl::_dlsym(handler, "getInstance");
  del = (deleteInst)Glibc::Libdl::_dlsym(handler, "deleteInstance");
  if (!get || !del || !_snake || !_fruit)
    throw std::exception();
  _fruit->moveFruit(_snake, _xyMap);
  _graphics = get(_xyMap);
}

Nibbler::Nibbler(void *handler)
{
  _xyMap.first = 20;
  _xyMap.second = 10;
  _snake = new Snake(_xyMap);
  _fruit = new Fruit(0, 0);
  get = (getInst)Glibc::Libdl::_dlsym(handler, "getInstance");
  del = (deleteInst)Glibc::Libdl::_dlsym(handler, "deleteInstance");
  if (!get || !del || !_snake || !_fruit)
    throw std::exception();
  _fruit->moveFruit(_snake, _xyMap);
  _graphics = get(_xyMap);
}

Nibbler::~Nibbler()
{
  delete _graphics;
  delete _snake;
  delete _fruit;
}

bool		Nibbler::runGame()
{
  t_directions	tmp;
  bool	        end = false;

  while (!_snake->checkCollision(_xyMap) && !end)
    {
      _graphics->updateDraw(*_snake, *_fruit, _xyMap);
      tmp = _snake->getDir();
      tmp = _graphics->getInput(_snake->getDir());
      if (tmp == 4)
	end = true;
      else
	{
	  _snake->setDir(tmp);
	  _snake->moveSnake();
	  if (_fruit->isEaten(_snake->getHead()))
	    {
	      _snake->addSnake();
	      if (_snake->getSize() != _xyMap.first * _xyMap.second)
		_fruit->moveFruit(_snake, _xyMap);
	      else
		end = true;
	    }
	  _snake->resetTail();
	}
    }
  return (end);
}
