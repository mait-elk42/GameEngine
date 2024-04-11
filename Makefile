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
SRCS= srcs/glad.cpp srcs/GameContext.cpp srcs/Shader.cpp srcs/GPUMemory.cpp 
SRCS_O= $(SRCS:.cpp=.o)
NAME= GameEngine

all: $(NAME)

$(NAME): $(SRCS_O) $(NAME).cpp
	$(CC) $(CFLAGS) $(NAME).cpp $(SRCS_O) -L ./lib -lglfw3 -lgdi32 -lopengl32 -o $(NAME).exe

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRCS_O)

fclean: clean
	rm -f $(NAME).exe

re: fclean all

.PHONY: clean
