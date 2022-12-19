CC			= 	gcc #-Wall -Wextra -Werror  -g # -fsanitize=address
RM			= 	/bin/rm -f
NAME		= 	so_long
INCLUDES	= 	-Iheaders/
MILIB		=	-I /usr/X11/include -g -L /usr/X11/lib -l minilibx-linux -framework OpenGL -framework AppKit

SRCS		=   $(shell find -name '*.c')
OBJS		= 	$(SRCS:.c=.o)


MLX_LIB_DIR = mlx_linux/
#directories with .h
LIBFT_INCLUDE = -ILIBFT/include
MLX_INCLUDE = -Imlx_linux

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ^ primeira dependencia
# @ nome da regra
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s -C mlx_linux
	@$(CC) $(^) $(MLX_FLAGS) -o $(@)

%.o: %.c $(MLX_LIB)
	@$(CC) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

bonus:	all

clean:
		@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)


re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

.PHONY: all re clean fclean m

