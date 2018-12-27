# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skunz <skunz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 14:30:14 by skunz             #+#    #+#              #
#    Updated: 2018/12/27 11:02:20 by skunz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################################### GENERAL ##################################

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC_DIR = ./src/

SRC = main.c map.c eventhandler.c raycast_main.c raycast_wall.c floorcast.c    \
		draw.c movement.c

###################################### OBJECTS #################################

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

################################ LIBRARIES - FRAMEWORK #########################

LIB_DIR = ./libraries

LIBFT = -L $(LIB_DIR)/libft/ -lft

MINILIB = -L $(LIB_DIR)/minilibx_macos -lmlx

FRAMEWORK = -framework OpenGL -framework AppKit

###################################### HEADERS #################################

INC_DIR = ./includes/

LIB_HEAD = $(LIB_DIR)/libft/includes/

MLX_HEAD = $(LIB_DIR)/minilibx_macos/

INC = -I $(LIB_HEAD) -I $(INC_DIR) -I $(MLX_HEAD)

###############################  COLORS AND TEXT  ##############################

#COLORS
COM_COLOR   = \033[0;36m
NO_COLOR    = \033[m

#TEXT
COM_STRING  = "Wolf3d Compilation Successful"
CLEAN_OBJ	= "Cleaned Wolf3d Objects"
CLEAN_NAME	= "Cleaned Wolf3d Binary"

######################################## RULES #################################

all: lib obj $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(LIBFT) $(MINILIB) $(FRAMEWORK) -g $^ -o $@
	@echo "$(COM_COLOR)$(COM_STRING)$(NO_COLOR)"

#OBJECTS

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(FLAGS) $(INC) -g -c $< -o $@

obj:
	@mkdir $(OBJ_DIR)

#WOLF

clean: libclean
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(COM_COLOR)$(CLEAN_OBJ)$(NO_COLOR)"

fclean: clean libfclean
	@/bin/rm -f $(NAME)
	@echo "$(COM_COLOR)$(CLEAN_NAME)$(NO_COLOR)"

#LIBFT

lib:
	@make -C $(LIB_DIR)/libft/ all

libfclean:
	@make -C $(LIB_DIR)/libft/ fclean

libclean:
	@make -C $(LIB_DIR)/libft/ clean

#MLX

mlx:
	@make -C $(LIB_DIR)/minilibx_macos/ all

mlxclean:
	@make -C $(LIB_DIR)/minilibx_macos/ clean

re: fclean all
