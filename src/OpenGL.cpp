//
// OpenGL.cpp for OpenGL in /home/laguer_s/Rendubis/nibbler
// 
// Made by laguer_s
// Login   <laguer_s@epitech.net>
// 
// Started on  Thu Apr  3 15:55:17 2014 laguer_s
// Last update Sun Apr  6 19:03:51 2014 laguer_s
//

#include	"OpenGL.hh"

OPENGL_Nib::OPENGL_Nib(const std::pair<int, int>& map)
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Nibbler",NULL);
  SDL_SetVideoMode((map.first + 4) * 8, (map.second + 2) * 8 + 4, 32, SDL_OPENGL);
  glMatrixMode( GL_PROJECTION);
  glLoadIdentity();
  gluLookAt(-0, -0, 0,
	    0, 0,-1,
	    0, 1, 0);
  gluOrtho2D(map.first,0,map.second,0);
}

OPENGL_Nib::~OPENGL_Nib()
{
  SDL_Quit();
}

t_directions	OPENGL_Nib::getInput(const t_directions dir)
{
  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	return (EXIT);
      if (this->event.type == SDL_KEYDOWN)
	{
	  if (this->event.key.keysym.sym == SDLK_ESCAPE)
	    return (EXIT);
	  if (this->event.key.keysym.sym == SDLK_LEFT)
	    {
	      if (dir == LEFT)
		return (UP);
	    return ((t_directions)(dir + 1));
	    }
	  if (this->event.key.keysym.sym == SDLK_RIGHT)
	    {
	      if (dir == UP)
	      return (LEFT);
	      return ((t_directions)(dir - 1));
	    }
      }
    }
  SDL_Delay(250);
  return (dir);
}

void		OPENGL_Nib::updateDraw(const Snake & s, const Fruit & f,
				       const std::pair<int, int>& map)
{
  glClear(GL_COLOR_BUFFER_BIT);
  draw_board(map);
  drawFruit(f);
  drawSnake(s);
  glFlush();
  SDL_GL_SwapBuffers();
}

extern "C"
{
  OPENGL_Nib	*getInstance(const std::pair<int,int> &map)
  {
    return new OPENGL_Nib(map);
  }

  void		deleteInstance(OPENGL_Nib *lib)
  {
    delete (lib);
  }
}
