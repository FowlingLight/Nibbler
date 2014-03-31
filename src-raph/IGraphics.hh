//
// IGraphics.hh for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Fri Mar 28 13:49:32 2014 Raphael Morand
// Last update Mon Mar 31 13:25:14 2014 Raphael Morand
//

#ifndef		__IGRAPHICS__
#define		__IGRAPHICS__

#include	<Snake.hh>

class		IGraphics
{
public:
  ~Igraphics() {};
  // totally const will just loop to get input and do the "wait" because the snake move on its own every X sec/msec etc.. 
  void		getInputs() const = 0;
  // may need to not be const but not sure from now...
  void		updateDraw(Snake &snake, std::pair<int, int>& XYmap) const = 0;
}

#endif
