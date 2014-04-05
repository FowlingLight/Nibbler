//
// OpenGL.hh for OpenGL in /home/laguer_s/Rendubis/nibbler
// 
// Made by laguer_s
// Login   <laguer_s@epitech.net>
// 
// Started on  Thu Apr  3 15:45:51 2014 laguer_s
// Last update Sat Apr  5 17:54:34 2014 benjamin horiot
//

#ifndef		_OPENGL_NIB_
#define		_OPENGL_NIB_

#include	<iostream>
#include	<SDL/SDL.h>
#include	<GL/gl.h>
#include	<GL/glu.h>
#include	<GL/glut.h>
#include	<vector>
#include	<utility>

#include	"Nibbler.hh"

class		OPENGL_Nib : public IGraphics
{
  SDL_Event	event;
public:
  OPENGL_Nib(const std::pair<int, int> & map);
  ~OPENGL_Nib();
  t_directions	getInput(const t_directions);
  void		updateDraw(const Snake &, const Fruit &, const std::pair<int, int> &);
  void		gameOver(const bool);
};

void		draw_board(const std::pair<int, int>&);
void		drawSnake(const Snake &s);
void		drawFruit(const Fruit &);

extern "C" {
  OPENGL_Nib	*getInstance(const std::pair<int, int>& map);
}

extern "C" {
  void		deleteInstance(OPENGL_Nib *);
}
#endif	/* _OPENGL_NIB_ */

