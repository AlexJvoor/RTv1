NAME = RTv1

# TODO enable flags
FLAGS = -Wall -Wextra #-Werror

MLXFLAGS = -L mlx -lmlx -framework OpenGL -framework AppKit

FTFLAGS = -L libft -lft 

LIBNUMFLAGS = -L libnum -lnum 

SRCS = main.c \
       safe_call.c \
       init_data.c \
       draw_figure.c \
       figure_cast_formulas.c

PARSE_SRC = parse.c \
            tools.c \
            figure.c \
            safe_call_parse.c

INCLUDES = -I libnum/include -I libft -I includes -I minilibx_macos

HEADERS = includes/rtv1.h

LIBFT = libft/libft.a

LIBNUM = libnum/libnum.a

MLX = mlx/libmlx.a

DIR_O = objs

DIR_S = src
DIR_PARSE_S = src/parse

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))
OBJS += $(addprefix $(DIR_O)/,$(PARSE_SRC:.c=.o))

all: $(NAME)

$(NAME): $(DIR_O) $(OBJS) $(HEADERS) $(MLX) $(LIBFT) $(LIBNUM)
	gcc  $(OBJS) $(FTFLAGS) $(LIBNUMFLAGS) $(MLXFLAGS) $(FLAGS) -o $(NAME)

$(DIR_O):
	mkdir -p $(DIR_O)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)
	gcc $(FLAGS) $(INCLUDES) -c -o $@ $<

$(DIR_O)/%.o: $(DIR_PARSE_S)/%.c $(HEADERS)
	gcc $(FLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):#libft/libft.a:
	@make -C ./libft

$(MLX):#mlx/libmlx.a:
	@make -C ./mlx

$(LIBNUM):#libnum/libnum.a:
	@make -C ./libnum

clean:
	@/bin/rm -rf $(DIR_O)
	@make clean -C ./libft
	@make clean -C ./mlx
	@make clean -C ./libnum

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C ./libnum
	@make fclean -C ./libft

re: fclean all

.PHONY: all dir clean fclean re