//
// SFML.hh for  in /home/hallelouia/Tek2/C++/cpp_nibbler/src-raph/SFML
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Apr  2 15:18:34 2014 Raphael Morand
// Last update Thu Apr  3 16:08:02 2014 Raphael Morand
//

#ifndef	__SFML_NIB__
#define	__SFML_NIB__

#include	<SFML/Graphics.hpp>

#include	"../IGraphics.hh"

class		SFML_Nib : public IGraphics
{
private:
  sf::WindowRender	wr;
  sf::Texture		spriteSheet;
  sf::Sprite		snakeHead;
  sf::Sprite		snakeBody;
  sf::Sprite		wall;
  sf::Sprite		_fruit;
public:
  SFML_Nib();
  ~SFML_Nib();
};

extern "C" {
  SFML_Nib		*getInstance();
}

extern "C" {
  void			deleteInstance();
}

#endif
