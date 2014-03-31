//
// Nibbler.hh for * in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Mar 26 13:05:01 2014 Raphael Morand
// Last update Wed Mar 26 14:32:10 2014 Raphael Morand
//

#ifndef		__NIBBLER__
#define		__NIBBLER__

#include	<pair>
#include	<vector>

#include	"Snake.h"

class		Nibbler
{
private :
  Snake			_snake;
  void			*_graphics;
  std::pair<int, int>	_xyMap;
public :
  Nibbler(const void *handler, const std::pair<int, int>& xyMap, int snakeSize);
  Nibbler(const void *handler, const int snakeSize);
  ~Nibbler();
  int			runGame();
};

#endif
