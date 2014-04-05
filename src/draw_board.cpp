//
// draw_board.cpp for draw_board in /home/laguer_s/Rendubis/nibbler
// 
// Made by laguer_s
// Login   <laguer_s@epitech.net>
// 
// Started on  Fri Apr  4 10:16:28 2014 laguer_s
<<<<<<< HEAD
// Last update Sat Apr  5 19:00:17 2014 laguer_s
=======
// Last update Sat Apr  5 18:02:17 2014 benjamin horiot
>>>>>>> 599e747f589d3c23a46bed4a46fc0dcdbbcfdba6
//

#include	"OpenGL.hh"

void		draw_board(const std::pair<int,int>& map)
{
  double	x;
  double	y;

  x = map.first;
  y = map.second;
  glBegin(GL_POINTS);
  glVertex2d(0,0);
  glVertex2d(x, y);
  /*    glVertex2d(x, -y);
  glVertex2d(-x, -y);
  glVertex2d(-x, y);
  glVertex2d(x, y);*/
  glEnd();
}

<<<<<<< HEAD
void		drawSnake(const Snake & s)
=======
//void		drawSnake(std::vector<std::pair<int, int> > & snake)
void		drawSnake(const Snake &s)
>>>>>>> 599e747f589d3c23a46bed4a46fc0dcdbbcfdba6
{
  int	i;
 
  i = 1;
  glBegin(GL_POINTS);
  while (i <= s.getSize())
    {
      glVertex2i(s.getSnake()[i].first, s.getSnake()[i].second);
      i++;
    }
  glEnd();
}

<<<<<<< HEAD
void		drawFruit(const Fruit & f)
{
  std::pair<int, int> fruit = f.getFruit();

=======
//void		drawFruit(const std::pair<int, int> & fruit)
void		drawFruit(const Fruit &f)
{
  std::pair<int, int> fruit = f.getFruit();

  std::cout << "drawFruit" << std::endl;
>>>>>>> 599e747f589d3c23a46bed4a46fc0dcdbbcfdba6
  glBegin(GL_POINTS);
  glVertex2i(fruit.first, fruit.second);
  glEnd();
}
