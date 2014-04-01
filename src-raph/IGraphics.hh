//
// IGraphics.hh for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Fri Mar 28 13:49:32 2014 Raphael Morand
// Last update Tue Apr  1 12:53:34 2014 Raphael Morand
//

#ifndef		__IGRAPHICS__
#define		__IGRAPHICS__

#include	"Nibbler.hh"
#include	"Fruit.hh"
#include	"Snake.hh"

class		IGraphics
{
public:
  ~IGraphics() {};
  // totally const will just loop to get input and do the "wait" because the snake move on its own every X sec/msec etc.. 
  virtual t_directions	getInput(const t_directions dir) const = 0;
  // may need to not be const but not sure from now...
  virtual void		updateDraw(const Snake &snake, const Fruit &fruit, std::pair<int, int>& XYmap) = 0;
  virtual void		gameOver(const bool Victory) = 0;
};

typedef IGraphics	*(*getInstance)();
typedef	void		(*deleteInstance)(IGraphics *);

#endif
