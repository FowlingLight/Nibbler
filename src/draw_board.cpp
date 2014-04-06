//
// draw_board.cpp for draw_board in /home/laguer_s/Rendubis/nibbler
// 
// Made by laguer_s
// Login   <laguer_s@epitech.net>
// 
// Started on  Fri Apr  4 10:16:28 2014 laguer_s
// Last update Sun Apr  6 20:55:54 2014 laguer_s
//

#include	"OpenGL.hh"

void		draw_board(const std::pair<int,int>& map)
{
  double	x;
  double	y;

  x = map.first;
  y = map.second;
  glBegin(GL_LINE_STRIP);
  glVertex2d(0, 0);
  glVertex2d(0, y);
  glVertex2d(x, y);
  glVertex2d(x, 0);
  glEnd();
}

void		drawSnake(const Snake & s)
{
  int	i;
 
  i = 1;
  glBegin(GL_LINE_STRIP);
  glVertex2i(s.getHead().first, s.getHead().second);
  while (i <= s.getSize())
    {
      glVertex2i(s.getSnake()[i].first, s.getSnake()[i].second);
      i++;
    }
  glEnd();
}

void		drawFruit(const Fruit & f)
{
  std::pair<int, int> fruit = f.getFruit();

  glBegin(GL_POINTS);
  glVertex2i(fruit.first, fruit.second);
  glEnd();
}
