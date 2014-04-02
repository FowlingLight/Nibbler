//
// SFML.cpp for  in /home/hallelouia/Tek2/C++/cpp_nibbler/src-raph/SFML
// 
// Made by Raphael Morand
// Login   <morand_c@epitech.net>
// 
// Started on  Wed Apr  2 15:18:30 2014 Raphael Morand
// Last update Wed Apr  2 16:01:11 2014 Raphael Morand
//

#include	"SFML.hh"

SFML_Nib		*getInstance()
{
  return new SFML_Nib();
}

void			deleteInstance(SFML_Nib *inst)
{
  delete inst;
}

SFML_Nib::SFML_Nib()
{
  
}

SFML_Nib::~SFML_Nib()
{
  delete wr;
  delete snakeHead;
  delete snakeBody;
  delete fruit;
  delete wall;
}
