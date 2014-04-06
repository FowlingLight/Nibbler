//
// SFML.hh for  in /home/hallelouia/Tek2/C++/cpp_nibbler/src-raph/SFML
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Apr  2 15:18:34 2014 Raphael Morand
// Last update Sun Apr  6 12:50:24 2014 Raphael Morand
//

#ifndef	__SFML_NIB__
#define	__SFML_NIB__

#include	<SFML/Graphics.hpp>
#include	<SFML/Window.hpp>
#include	<SFML/System.hpp>

#include	"IGraphics.hh"
#include	"Snake.hh"
#include	"Fruit.hh"
#include	"Glibc.hh"

class		SFML_Nib : public IGraphics
{
private:
  sf::RenderWindow	wr;
  sf::Texture		spriteSheet;
  sf::Sprite		snakeHead;
  sf::Sprite		snakeBody;
  sf::Sprite		wall;
  sf::Sprite		_fruit;
  sf::RenderTexture	rt;
public:
  SFML_Nib(const std::pair<int, int>& map);
  virtual ~SFML_Nib();
  virtual t_directions	getInput(const t_directions dir);
  virtual void		updateDraw(const Snake& snake, const Fruit& fruit,
			   const std::pair<int, int>& map);
};

extern "C" {
  SFML_Nib		*getInstance(const std::pair<int, int>& map);
}

extern "C" {
  void			deleteInstance(SFML_Nib *inst);
}

#endif
