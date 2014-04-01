//
// Fruit.hh for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Mar 26 14:38:17 2014 Raphael Morand
// Last update Tue Apr  1 09:51:17 2014 Raphael Morand
//

#ifndef		__FRUIT__
#define		__FRUIT__

#include	<utility>
#include	"Snake.hh"
#include	"Glibc.hh"

class		Fruit
{
private :
  std::pair<int, int>	_pos;
public :
  Fruit(const int x, const int y);
  ~Fruit();
  const std::pair<int, int>&	getFruit() const;
  const bool			isEaten(const std::pair<int, int>& SnakeHead) const;
  void				moveFruit(const Snake& snake, 
					  const std::pair<int, int>& xyMap);
};

#endif
