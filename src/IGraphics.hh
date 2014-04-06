//
// IGraphics.hh for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Fri Mar 28 13:49:32 2014 Raphael Morand
// Last update Sun Apr  6 12:50:55 2014 Raphael Morand
//

#ifndef		__IGRAPHICS__
#define		__IGRAPHICS__

#include	"Fruit.hh"
#include	"Snake.hh"

class		IGraphics
{
public:
  virtual ~IGraphics() {};

  virtual t_directions	getInput(const t_directions dir) = 0;
  virtual void		updateDraw(const Snake &snake, const Fruit &fruit, const std::pair<int, int>& XYmap) = 0;
};

typedef IGraphics	*(*getInst)(const std::pair<int, int>&);
typedef	void		(*deleteInst)(IGraphics *);

#endif
