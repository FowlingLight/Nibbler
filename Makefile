##
## Makefile for rush in /home/horiotb/Documents/projets/rush/1
## 
## Made by benjamin horiot
## Login   <horiot_b@epitech.net>
## 
## Started on  Sat Mar  8 10:56:32 2014 benjamin horiot
## Last update Thu Mar 20 15:28:47 2014 benjamin horiot
##

SRC	=	src/error.cpp \
		src/main.cpp \
		src/ncurses.cpp \
		src/snake.cpp \

OBJ	=	$(SRC:.cpp=.o)

NAME	=	nibbler


all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -W -Wall -Wextra -Werror -o $(NAME) $(OBJ) -ldl -lcurses


clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
