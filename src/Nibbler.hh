//
// Nibbler.hh for * in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Mar 26 13:05:01 2014 Raphael Morand
// Last update Thu Apr  3 15:00:41 2014 benjamin horiot
//

#ifndef		__NIBBLER__
#define		__NIBBLER__

#include	<utility>
#include	<vector>

#include	"IGraphics.hh"
#include	"Fruit.hh"
#include	"Glibc.hh"
#include	"Snake.hh"

class		Nibbler
{
private :
  Snake			*_snake;
  Fruit			*_fruit;
  IGraphics		*_graphics;
  std::pair<int, int>	_xyMap;
  getInst		get;
  deleteInst		del;
public :
  Nibbler(void *handler, const std::pair<int, int>& xyMap);
  Nibbler(void *handler);
  ~Nibbler();
  bool			runGame();
};

#endif
