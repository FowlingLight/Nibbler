//
// Nibbler.hh for * in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Mar 26 13:05:01 2014 Raphael Morand
// Last update Tue Apr  1 09:55:54 2014 Raphael Morand
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
  Nibbler(const void *handler, const std::pair<int, int>& xyMap);
  Nibbler(const void *handler, );
  ~Nibbler();
  int			runGame();
};

#endif
