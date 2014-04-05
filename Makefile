##
## Makefile for rush in /home/horiotb/Documents/projets/rush/1
## 
## Made by benjamin horiot
## Login   <horiot_b@epitech.net>
## 
## Started on  Sat Mar  8 10:56:32 2014 benjamin horiot
## Last update Sat Apr  5 17:05:44 2014 laguer_s
##

SRC_NC	=	src/Fruit.cpp \
		src/Ncurses.cpp \
		src/Snake.cpp \
		src/Glibc.cpp

SRC_SF	=	src/Fruit.cpp \
		src/SFML.cpp \
		src/Snake.cpp \
		src/Glibc.cpp

SRC_OGL =       src/draw_board.cpp \
                src/OpenGL.cpp

SRC	=	src/Fruit.cpp \
		src/Glibc.cpp \
		src/main.cpp \
		src/Nibbler.cpp \
		src/Snake.cpp

OBJ_SF	=	$(SRC_SF:.cpp=.o)

OBJ_NC	=	$(SRC_NC:.cpp=.o)

OBJ_OGL =       $(SRC_OGL:.cpp=.o)

OBJ	=	$(SRC:.cpp=.o)

NAME_SF	=	lib_nibbler_sfml.so

NAME_NC	=	lib_nibbler_ncurses.so

NAME_OGL=       lib_nibbler_opengl.so

NAME	=	nibbler

CPPFLAGS	=	-fPIC -W -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_NC) $(OBJ_SF) $(OBJ_OGL)
		g++ -o $(NAME) $(OBJ) -ldl
		g++ -shared -o $(NAME_NC) $(OBJ_NC) -lncurses
		g++ -shared -o $(NAME_SF) $(OBJ_SF) -lsfml-window -lsfml-system -lsfml-graphics
		g++ -shared -o $(NAME_OGL) $(OBJ_OGL) -lglut -lGL -lGLU -lX11 -lXmu -lXi -lm -lSDL
clean:
		rm -f $(OBJ) $(OBJ_NC) $(OBJ_SF) $(OBJ_OGL)

fclean:		clean
		rm -f $(NAME) $(NAME_NC) $(OBJ_SF) $(NAME_OGL)

re:		fclean all
