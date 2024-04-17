# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 11:20:25 by mait-elk          #+#    #+#              #
#    Updated: 2024/04/10 11:20:25 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
CC= c++
# CC= /mnt/c/MinGW/bin/c++.exe // TMP 
CFLAGS= -std=c++11 -I $(INC) 
INC = include/
SRCS=	srcs/glad.cpp srcs/GameContext.cpp srcs/Shader.cpp \
		srcs/VAO.cpp srcs/VBO.cpp \
		srcs/Vector3.cpp srcs/Vector2.cpp \
		srcs/Transform.cpp srcs/GameObject.cpp 
SRCS_O= $(SRCS:.cpp=.bin)
LIBS= 
NAME= GameEngine

ifeq ($(UNAME_S), Linux) #For Linux
	ECHO_MESSAGE = "Linux"
	LIBS = -lGl
endif

ifeq ($(UNAME_S), Darwin) #For APPLE
	ECHO_MESSAGE = "Mac OS X"
	LIBS = -L lib -lglfw3M -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
endif

ifeq ($(UNAME_S), Windows_NT) #For Windows
	ECHO_MESSAGE = "Windows"
	LIBS = -L lib -lglfw3W -lgdi32 -lopengl32 -limm32 -mwindows
endif


all: $(NAME)

$(NAME): $(SRCS_O) $(NAME).cpp
	@echo "Compiling Exec File" $(NAME) "For" $(ECHO_MESSAGE)
	@$(CC) $(CFLAGS) $(NAME).cpp $(SRCS_O) -L ./lib $(LIBS) -o $(NAME)

%.bin: %.cpp
	@echo "Compiling Script" $<
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(SRCS_O)
	@echo "Removing Bin Files"

fclean: clean
	@rm -f $(NAME).exe
	@echo "Removing Exec File"

re: fclean all

.PHONY: clean
