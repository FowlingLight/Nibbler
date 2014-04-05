//
// OpenGL.cpp for OpenGL in /home/laguer_s/Rendubis/nibbler
// 
// Made by laguer_s
// Login   <laguer_s@epitech.net>
// 
// Started on  Thu Apr  3 15:55:17 2014 laguer_s
// Last update Sat Apr  5 18:02:05 2014 benjamin horiot
//

#include	"OpenGL.hh"

OPENGL_Nib::OPENGL_Nib(const std::pair<int, int>& map)
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Nibbler",NULL);
  SDL_SetVideoMode((map.first + 2) * 8, (map.second + 2) * 8, 32, SDL_OPENGL);
  glMatrixMode( GL_PROJECTION);
  glLoadIdentity();
  //  glScalef(2, 2,0.0);
  gluOrtho2D(0, map.first, 0, map.second);
}

OPENGL_Nib::~OPENGL_Nib()
{
  SDL_Quit();
}

t_directions	OPENGL_Nib::getInput(const t_directions dir)
{
  SDL_WaitEvent(&(this->event));
  if (this->event.type == SDL_QUIT)
    exit(1);
  else if (this->event.type == SDL_KEYDOWN)
    {
      if (this->event.key.keysym.sym == SDLK_q)
	return ((t_directions)((int)dir - 1));
      else if (this->event.key.keysym.sym == SDLK_d)
	return ((t_directions)((int)dir - 1));
    }
  return (dir);
}

void		OPENGL_Nib::updateDraw(const Snake &s, const Fruit &f,
				       const std::pair<int, int> &map)
{
  glClear(GL_COLOR_BUFFER_BIT);
  draw_board(map);
  drawFruit(f);
  drawSnake(s);
  glFlush();
  SDL_GL_SwapBuffers();
}

void		OPENGL_Nib::gameOver(const bool lose)
{
  (void)lose;
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
