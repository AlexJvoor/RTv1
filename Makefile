NAME = RTv1

# TODO enable flags
FLAGS = -Wall -Wextra -g#-Werror

MLXFLAGS = -L mlx -lmlx -framework OpenGL -framework AppKit

FTFLAGS = -L libft -lft 

SRCS = main.c \
       safe_call.c \
       init_data.c \
       draw_figure.c \
       figure_cast_formulas.c \
	   update_screen.c \
	   figures_normal.c \
	   find_color.c \
	   texturing_sphere.c \
	   buttons_variants.c

PARSE_SRC = parse.c \
            tools.c \
            parse_float.c \
            parse_figure_params.c \
            parse_figure_tools.c \
            parse_figure.c \
            parse_light.c \
            parse_camera.c \
            safe_call_parse.c

VEC_SRC = vec_1.c \
		  vec_2.c \
		  vec_3.c

INCLUDES = -I libft -I includes -I minilibx_macos

HEADERS = includes/rtv1.h

LIBFT = libft/libft.a

MLX = mlx/libmlx.a

DIR_O = objs

DIR_S = src
DIR_PARSE_S = src/parse
DIR_VEC_S = src/vec_operations

OBJS = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))
OBJS += $(addprefix $(DIR_O)/,$(PARSE_SRC:.c=.o))
OBJS += $(addprefix $(DIR_O)/,$(VEC_SRC:.c=.o))

all: $(NAME)

$(NAME): $(DIR_O) $(OBJS) $(HEADERS) $(MLX) $(LIBFT)
	gcc  $(OBJS) $(FTFLAGS) $(MLXFLAGS) $(FLAGS) -o $(NAME)
	sh ./hohow/priv.sh

$(DIR_O):
	mkdir -p $(DIR_O)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)
	gcc $(FLAGS) $(INCLUDES) -c -o $@ $<

$(DIR_O)/%.o: $(DIR_PARSE_S)/%.c $(HEADERS)
	gcc $(FLAGS) $(INCLUDES) -c -o $@ $<

$(DIR_O)/%.o: $(DIR_VEC_S)/%.c $(HEADERS)
	gcc $(FLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):#libft/libft.a:
	@make -C ./libft

$(MLX):#mlx/libmlx.a:
	@make -C ./mlx

clean:
	@/bin/rm -rf $(DIR_O)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all dir clean fclean re
