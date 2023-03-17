RM			=	/bin/rm -f
NAME		=	so_long
INCLUDES	=	-Iheaders/

SRCS		=	main.c moviment.c endgame.c\
				 get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				
OBJS		=	$(SRCS:%.c=%.o)
EXEC		=	./so_long

SRC_DIR = src
MLX_LIB_DIR = mlx/
L_Flags = /usr/lib -lXext -lX11
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx -L$(L_Flags)

# ^ primeira dependencia
# @ nome da regra
all:
		gcc $(SRCS) $(MLX_FLAGS) -o $(EXEC)
		$(EXEC)

clean:
		$(RM) $(EXEC)

fclean: clean
		$(RM) $(NAME)

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

.PHONY: all re clean fclean m

