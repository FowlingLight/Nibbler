//
// SFML.cpp for  in /home/hallelouia/Tek2/C++/cpp_nibbler/src-raph/SFML
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Apr  2 15:18:30 2014 Raphael Morand
// Last update Thu Apr  3 16:48:15 2014 Raphael Morand
//

#include	<exception>

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
  wr.create(sf::videoMode(map.first + 2 * 32, map.second + 2), "Nibbler");
  if (!_texture.loadFromFile("spriteSheet.png"))
    throw std::exception();
  //load sprites
}

SFML_Nib::~SFML_Nib()
{
}

t_directions		Nibbler::getInput(const t_directions dir)
{
  sf::event		event;

  while (wr.pollEvent(event))
    {
      if (event.type == sf::Event::Closed
	  || (event.type == sf::Event::KeyPressed
	      && event.key.code == sf::Keyboard::Escape))
	return (EXIT);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::UP))
	{
	  if (dir == LEFT)
	    return (UP);
	  return (dir + 1);
	}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::DOWN))
	{
	  if (dir == UP)
	    return (LEFT);
	  return (dir - 1);
	}
      return (dir);
    }
  return (dir);
}

bool		is_food(const int x, const int y, const std::pair<int, int>& fruit)
{
  if (x = fruit.first && y == fruit.second)
    return (true);
  return (false);
}

bool		is_head(const std::pair<int, int> head)
{
  if (x = fruit.first && y == fruit.second)
    return (true);
  return (false);
}

bool		is_snake(const vector<pair<int, int> >& snake, const int x, const int y)
{
  int		i = 1;
  
  while (i < snake.size())
    {
      if (snake[i].first == x && snake[i].second == y)
	return (true);
      ++i;
    }
  return (false);
}

void		updateDraw(const Snake& snake, const Fruit& fruit,
			   const std::pair<int, int>& map)
{
  sf::RenderTexture	rt;
  int			x = 0;
  int			y = 0;

  rt.clear();
  while (x <= map.first)
    {
      y = 0;
      while (y <= map.second)
	{
	  if (x == 0 || y == 0 || x == map.first || y == map.second)
	    {
	      wall.setPosition(x * 32, y * 32);
	      rt.draw(wall);
	    }
	  else if (is_fruit(x, y, fruit.getFruit()))
	    {
	      fruit.setPosition(x * 32, y * 32);
	      rt.draw(_fruit);
	    }
	  else if (is_head(snake.getHead(), x, y))
	    {
	      snakeHead.setPosition(x * 32, y * 32);
	      rt.draw(snakeHead);
	    }
	  else if (is_snake(snake.getSnake(), x, y))
	    {
	      snakeBody.setPosition(x * 32, y * 32);
	      rt.draw(snakeHead);
	    }
	  ++y;
	}
      ++x;
    }
  wr.clear();
  wr.draw(rt);
}
