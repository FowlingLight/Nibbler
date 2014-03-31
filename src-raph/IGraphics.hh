//
// IGraphics.hh for  in /home/hallelouia/Tek2/C++/nibbler-loc
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Fri Mar 28 13:49:32 2014 Raphael Morand
// Last update Fri Mar 28 14:00:27 2014 Raphael Morand
//

#ifndef		__IGRAPHICS__
#define		__IGRAPHICS__

#include	<Snake.hh>

class		IGraphics
{
public:
  ~Igraphics() {};
  void		Update() const = 0;
  void		Draw(Snake &snake, std::pair<int, int>& XYmap) const = 0;
}

#endif
