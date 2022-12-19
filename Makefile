RM			=	/bin/rm -f
NAME		=	so_long
INCLUDES	=	-Iheaders/

SRCS		=	main.c moviment.c endgame.c
OBJS		=	$(SRCS:%.c=%.o)
EXEC		=	./a.out


MLX_LIB_DIR = mlx/

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx -L/usr/lib -lXext -lX11

# ^ primeira dependencia
# @ nome da regra
all:
		gcc $(SRCS) $(MLX_FLAGS)
		$(EXEC)

clean:
		$(RM) $(EXEC)

fclean: clean
		$(RM) $(NAME)

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

.PHONY: all re clean fclean m

