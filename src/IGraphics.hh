//
// IGraphics.hh for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Fri Mar 28 13:49:32 2014 Raphael Morand
// Last update Thu Apr  3 16:47:34 2014 benjamin horiot
//

#ifndef		__IGRAPHICS__
#define		__IGRAPHICS__

//#include	"Nibbler.hh"
#include	"Fruit.hh"
//#include	"Snake.hh"

class		IGraphics
{
public:
  virtual ~IGraphics() {};
  // totally const will just loop to get input and do the "wait" because the snake move on its own every X sec/msec etc.. 
  virtual t_directions	getInput(const t_directions dir) const = 0;
  // may need to not be const but not sure from now...
  virtual void		updateDraw(const Snake &snake, const Fruit &fruit, const std::pair<int, int>& XYmap) = 0;
  virtual void		gameOver(const bool Victory) = 0;
};

typedef IGraphics	*(*getInst)(const std::pair<int, int>&);
typedef	void		(*deleteInst)(IGraphics *);

#endif
