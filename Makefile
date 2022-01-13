SRCS =		fractal.c julia.c mandelbrot.c ft_strncmp.c\
			fractal_inits.c colors.c tricorn.c hooks.c\
			double_atoi.c fractal_draw_utils.c
OBJS =		$(SRCS:.c=.o)
NAME =		fractol
HEADERS =   fractal.h key_macos.h

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./mlx/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

GCC =		gcc
RM =		rm -f
CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)

%.o: %.c
	$(GCC) $(CFLAGS) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(MINILIBX) $(OBJS)
	$(GCC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

$(MINILIBX):
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
			$(RM) $(OBJS)
			
fclean:		clean
			$(RM) $(NAME) 

re:			fclean all

.PHONY:		all clean clean fclean re