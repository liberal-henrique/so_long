# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 15:05:43 by lliberal          #+#    #+#              #
#    Updated: 2023/03/30 16:12:38 by lliberal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC			=	gcc -g3 -fsanitize=address
CC			=	gcc -g3
# CFLAGS		=	-Wall -Wextra -Werror
RM			=	/bin/rm -f
NAME		=	so_long
INCLUDES	=	-Iheaders/
GET_I		=	utils/get_next_line/get_next_line.h

SRCS		=	structs/structs.c \
				utils/get_next_line/get_next_line.c \
				utils/get_next_line/get_next_line_utils.c \
				main.c \
				canvas/canvas_init.c \
				canvas/playable_area.c \
				window/window_init.c \
				images/images_init.c \
				images/mlx_pixel_render.c \
				images/image_render.c \
				images/print_ground.c \
				images/print_collectables.c \
				array_2d/create_array_2d.c \
				array_2d/flood_fill.c \
				checkers/checker_maps_elements.c \
				checkers/ft_validate.c \
				checkers/utils_check.c \
				moviments/keypress.c \
				moviments/get_player_position.c \
				cleaner/endgame.c


OBJS		=	$(SRCS:.c=.o)

# SRC_DIR = src
MLX_LIB_DIR = mlx/
L_Flags = /usr/lib -lXext -lX11
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx -L$(L_Flags)

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(SRCS) $(MLX_FLAGS) $(GET_I) -o $(NAME)
in: all
	./so_long ./maps/map.ber

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

.PHONY: all re clean fclean m

