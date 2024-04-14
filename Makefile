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

# CC= c++
CC= /mnt/c/MinGW/bin/c++.exe
CFLAGS= -I $(INC)
INC = include/
SRCS= srcs/glad.cpp srcs/GameContext.cpp srcs/Shader.cpp srcs/VAO.cpp srcs/VBO.cpp 
SRCS_O= $(SRCS:.cpp=.bin)
NAME= GameEngine

all: $(NAME)

$(NAME): $(SRCS_O) $(NAME).cpp
	@echo "Compiling Exec File" $(NAME)
	@$(CC) $(CFLAGS) $(NAME).cpp $(SRCS_O) -L ./lib -lglfw3 -lGLEW -lgdi32 -lopengl32 -lglut32 -o $(NAME).exe -mwindows

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
