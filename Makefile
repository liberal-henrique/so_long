# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 15:05:43 by lliberal          #+#    #+#              #
#    Updated: 2023/03/22 20:47:30 by lliberal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc -g
CFLAGS		=	-Wall -Wextra -Werror
RM			=	/bin/rm -f
NAME		=	so_long
INCLUDES	=	-Iheaders/

SRCS		=	main.c moviment.c endgame.c checkers.c \
				checkers_2.c image_2.c image.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \

OBJS		=	$(SRCS:%.c=%.o)
EXEC		=	./so_long

SRC_DIR = src
MLX_LIB_DIR = mlx/
L_Flags = /usr/lib -lXext -lX11
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx -L$(L_Flags)

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) $(MLX_FLAGS) -o $(EXEC)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

.PHONY: all re clean fclean m

