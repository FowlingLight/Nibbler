//
// SFML.cpp for  in /home/hallelouia/Tek2/C++/cpp_nibbler/src-raph/SFML
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Apr  2 15:18:30 2014 Raphael Morand
// Last update Sun Apr  6 12:50:38 2014 Raphael Morand
//

#include	<exception>
#include	<iostream>

#include	"SFML.hh"

extern "C"
{
SFML_Nib		*getInstance(const std::pair<int, int>& map)
{return new SFML_Nib(map);}

void			deleteInstance(SFML_Nib *inst)
{delete inst;}
}

SFML_Nib::SFML_Nib(const std::pair<int, int>& map)
{
  wr.create(sf::VideoMode((map.first + 2) * 8, (map.second + 2) * 8), "Nibbler");
  wr.setKeyRepeatEnabled(false);
  rt.create(8 * (map.first + 2), 8 * (map.second + 2));
  if (!wr.isOpen())
    throw std::exception();
  if (!spriteSheet.loadFromFile("./ressources/Nibbler.bmp"))
    throw std::exception();
  snakeHead.setTexture(spriteSheet);
  snakeHead.setTextureRect(sf::IntRect(0,0,8,8));
  snakeBody.setTexture(spriteSheet);
  snakeBody.setTextureRect(sf::IntRect(8,0,8,8));
  wall.setTexture(spriteSheet);
  wall.setTextureRect(sf::IntRect(16,0,8,8));
  _fruit.setTexture(spriteSheet);
  _fruit.setTextureRect(sf::IntRect(24,0,8,8));
}

SFML_Nib::~SFML_Nib()
{
}

t_directions		SFML_Nib::getInput(const t_directions dir)
{
  t_directions		tmp;
  sf::Event		event;
  sf::Clock		clock;
  sf::Time		time;
  sf::Time		time2;

  tmp = dir;
  time = clock.getElapsedTime();
  time2 = time;
  while (time2.asMilliseconds() < time.asMilliseconds() + 150)
    {
      while (wr.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed
	      || (event.type == sf::Event::KeyPressed 
		  && event.key.code == sf::Keyboard::Escape))
	    tmp = EXIT;
	  else if (event.type == sf::Event::KeyPressed 
		  && event.key.code == sf::Keyboard::Right)
	    {
	      if (dir == 3)
		tmp = (t_directions)0;
	      else
		tmp = (t_directions)((int)dir + 1);
	    }
	  else if (event.type == sf::Event::KeyPressed 
		  && event.key.code == sf::Keyboard::Left)
	    {
	      if (dir == 0)
		tmp = (t_directions)3;
	      else
	    tmp = (t_directions)((int)dir - 1);
	    }
	}
      time2 = clock.getElapsedTime();
    }
  return (tmp);
}
  bool		is_food(const int x, const int y, const std::pair<int, int>& fruit)
{
  if (x == fruit.first && y == fruit.second)
    return (true);
  return (false);
}

bool		is_head(const std::pair<int, int> head, int x, int y)
{
  if (x == head.first && y == head.second)
    return (true);
  return (false);
}

bool		is_snake(const std::vector<std::pair<int, int> >& snake, const int x, const int y)
{
  unsigned int		i = 1;
  
  while (i < snake.size())
    {
      if (snake[i].first == x && snake[i].second == y)
	return (true);
      ++i;
    }
  return (false);
}

void		SFML_Nib::updateDraw(const Snake& snake, const Fruit& fruit,
				     const std::pair<int, int>& map)
{
  sf::Sprite		sp;
  int			x = 0;
  int			y = 0;

  rt.clear();
  y = 0;
  while (y <= map.second + 1)
    {
      x = 0;
      while (x <= map.first + 1)
	{
	  if (x == 0 || y == 0 || x == map.first + 1 || y == map.second + 1)
	    {
	      wall.setPosition(x * 8, y * 8);
	      rt.draw(wall);
	    }
	  else if (is_food(x, y, fruit.getFruit()))
	    {
	      _fruit.setPosition(x * 8, ((map.second + 1) - y) * 8);
	      rt.draw(_fruit);
	    }
	  else if (is_head(snake.getHead(), x, y))
	    {
	      snakeHead.setPosition(x * 8, ((map.second + 1)- y) * 8);
	      rt.draw(snakeHead);
	    }
	  else if (is_snake(snake.getSnake(), x, y))
	    {
	      snakeBody.setPosition(x * 8, ((map.second + 1) - y) * 8);
	      rt.draw(snakeBody);
	    }
	  ++x;
	}
      ++y;
    }
  sp.setTexture(rt.getTexture());
  sp.setPosition(0,0);
  wr.clear();
  wr.draw(sp);
  wr.display();
}
