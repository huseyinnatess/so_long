NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = main.c \
	  free.c \
	  map_control.c \
	  mlx_include.c \
	  move_control.c \
	  move.c \
	  check_file.c

FT_PRINTF_PATH = ./ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

MINILIBX_PATH = ./minilibx

all : $(NAME)

$(NAME): $(FT_PRINTF) mlx
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(FT_PRINTF) -L $(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH) all

mlx:
	make -C $(MINILIBX_PATH) all

clean:
	make -C $(FT_PRINTF_PATH) clean
	make -C $(MINILIBX_PATH) clean

fclean: clean
	make -C $(FT_PRINTF_PATH) fclean
	make -C $(MINILIBX_PATH) clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re