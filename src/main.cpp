/*
** main.cpp for main in /home/horiotb/Documents/projets/c++/nibler/src
** 
** Made by benjamin horiot
** Login   <horiot_b@epitech.net>
** 
** Started on  Mon Mar 17 11:08:57 2014 benjamin horiot
** Last update Fri Mar 21 10:02:46 2014 benjamin horiot
*/

#include "nibbler.hh"

int		my_putusage()
{
  std::cerr << "Usage : ./nibler width height LIB.so" << std::endl;
  return (-1);
}

int		check_size(int width, int height)
{
  if (width < 5 || width > 30 || height < 5 || height > 30)
    return (my_puterror("Enter a map between 5x5 and 30x30", 0));
  return (1);
}

int		check_lib(char *name)
{
  void		*lib;

  lib = dlopen(name, RTLD_LAZY);
  dlclose(lib);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac != 4)
    return (my_putusage());

  int			width;
  int			height;
  std::stringstream	tmp1(av[1]);
  std::stringstream	tmp2(av[2]);
  NCurses		n(av[3]);

  tmp1 >> width;
  tmp2 >> height;
  n.game(width, height);
  //  if (!check_size(width, height) || !check_lib(av[3]))
  //    return (-1);
}
