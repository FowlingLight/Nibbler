/*
** error.cpp for snake in /home/horiotb/Documents/projets/c++/nibler/src
** 
** Made by benjamin horiot
** Login   <horiot_b@epitech.net>
** 
** Started on  Mon Mar 17 11:10:34 2014 benjamin horiot
** Last update Fri Mar 21 10:02:40 2014 benjamin horiot
*/

#include "nibbler.hh"

int		my_puterror(std::string str, int to_ret)
{
  std::cerr << str << std::endl;
  return (to_ret);
}

int		my_fcterror(char *name, int to_ret)
{
  std::cerr << "The " << name << " function failded" << std::endl;
  return (to_ret);
}

int		my_errno(char *name, int to_ret)
{
  std::cerr << name << " : " << strerror(errno) << std::endl;
  return (to_ret);
}
