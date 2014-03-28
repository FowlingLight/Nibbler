/*
** snake.cpp for snake in /home/horiotb/Documents/projets/c++/nibler/src
** 
** Made by benjamin horiot
** Login   <horiot_b@epitech.net>
** 
** Started on  Wed Mar 19 14:17:15 2014 benjamin horiot
// Last update Tue Mar 25 17:28:55 2014 Raphael Morand
*/

#include "nibbler.hh"

Snake::Snake(int x, int y)
{
  _dir = 0;
  _head[0] = x;
  _head[1] = y;
}

int		Snake::getHeadX() const
{
  return (_head[0]);
}

int		Snake::getHeadY() const
{
  return (_head[1]);
}

void		Snake::setHead(int x, int y)
{
  _head[0] = x;
  _head[1] = y;
}

std::vector<int>	Snake::getTailX() const
{
  return (_tailx);
}

void		Snake::addTailX(int x)
{
  _tailx.push_back(x);
}

std::vector<int>	Snake::getTailY() const
{
  return (_taily);
}

void		Snake::addTailY(int y)
{
  _taily.push_back(y);
}

int		Snake::getDir() const
{
  return (_dir);
}

void		Snake::setDir(bool plus)
{
  if (plus)
    _dir++;
  else
    _dir--;
}
