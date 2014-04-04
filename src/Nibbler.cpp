//
// Nibbler.cpp for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Mar 26 13:04:56 2014 Raphael Morand
// Last update Fri Apr  4 17:34:21 2014 Raphael Morand
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
    {
      if (!get)
	std::cout << "get" << std::endl;
      if (!del)
	std::cout << "del" << std::endl;
      if (!_snake)
	std::cout << "snake" << std::endl;
      if (!_fruit)
	std::cout << "fruit" << std::endl;
      throw std::exception();
    }
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
  bool		victory = false;

  while (!_snake->checkCollision(_xyMap) && !victory)
    {
      _graphics->updateDraw(*_snake, *_fruit, _xyMap);
      tmp = _snake->getDir();
      tmp = _graphics->getInput(_snake->getDir());
      if (tmp == 4)
	victory = true;
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
		victory = true;
	    }
	  _snake->resetTail();
	}
    }
  return (victory);
}
