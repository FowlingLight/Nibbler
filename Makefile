##
## Makefile for rush in /home/horiotb/Documents/projets/rush/1
## 
## Made by benjamin horiot
## Login   <horiot_b@epitech.net>
## 
## Started on  Sat Mar  8 10:56:32 2014 benjamin horiot
## Last update Fri Apr  4 17:34:56 2014 benjamin horiot
##

SRC_NC	=	src/Fruit.cpp \
		src/Ncurses.cpp \
		src/Snake.cpp \
		src/Glibc.cpp

SRC	=	src/Fruit.cpp \
		src/Glibc.cpp \
		src/main.cpp \
		src/Nibbler.cpp \
		src/Snake.cpp

OBJ_NC	=	$(SRC_NC:.cpp=.o)

OBJ	=	$(SRC:.cpp=.o)

NAME_NC	=	lib_nibbler_ncurses.so

NAME	=	nibbler

CPPFLAGS	=	-fPIC -W -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_NC)
		g++ -o $(NAME) $(OBJ) -ldl
		g++ -shared -o $(NAME_NC) $(OBJ_NC) -lncurses

clean:
		rm -f $(OBJ) $(OBJ_NC)

fclean:		clean
		rm -f $(NAME) $(NAME_NC)

re:		fclean all
