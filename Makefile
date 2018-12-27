# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skunz <skunz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 14:30:14 by skunz             #+#    #+#              #
#    Updated: 2018/12/26 18:52:28 by skunz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## GENERAL ##

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror

## SOURCES

SRC_DIR = ./src/

SRC = main.c map.c eventhandler.c raycast_main.c raycast_wall.c floorcast.c \
		draw.c movement.c

## OBJECTS

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

## libraries - framework ##

LIB_DIR = ./libraries

LIBFT = -L $(LIB_DIR)/libft/ -lft

MINILIB = -L $(LIB_DIR)/minilibx_macos -lmlx

FRAMEWORK = -framework OpenGL -framework AppKit

### HEADERS

INC_DIR = ./includes/

LIB_HEAD = $(LIB_DIR)/libft/includes/

MLX_HEAD = $(LIB_DIR)/minilibx_macos/

INC = -I $(LIB_HEAD) -I $(INC_DIR) -I $(MLX_HEAD)

############## RULES ##############

all: lib obj $(NAME)

$(NAME): $(OBJ)
	gcc -fsanitize=address $(FLAGS) $(LIBFT) $(MINILIB) $(FRAMEWORK) -g $^ -o $@

## OBJECTS RULES

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(FLAGS) $(INC) -g -c $< -o $@

obj:
	mkdir $(OBJ_DIR)

## WOLF RULES

clean: libclean
	/bin/rm -rf $(OBJ_DIR)

fclean: libfclean clean
	/bin/rm -f $(NAME)

## LIB RULES

lib:
	make -C $(LIB_DIR)/libft/ all

libfclean:
	make -C $(LIB_DIR)/libft/ fclean

libclean:
	make -C $(LIB_DIR)/libft/ clean

re: fclean all
