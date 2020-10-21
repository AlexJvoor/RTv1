#ifndef RTV1_H
# define RTV1_H
#include "stdio.h"
#include "math.h"
#include "mlx.h"
#include "libnum.h"
#include "libft.h"

#define WIDTH 1000
#define HEIGHT 1000
#define VX 1.0 / WIDTH 
#define VY 1.0 / HEIGHT
#define H_HEIGHT HEIGHT / 2
#define H_WIDTH WIDTH / 2

#define OBJ_SHINE	100

#define FOV 1,0472// == rads 60 | 1,5708 == rads 90

//TODO для фикса рыбьего глаза м. просчитывать каждую точку как z = sqrt(x^2 + y^2) (?возможно?)

#define		OBJ_COUNT 4

typedef struct	s_obj	t_obj;

#define TRUE	1
#define FALSE	0

typedef enum	e_type
{
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	LIGHT
}				t_type;

typedef struct		s_texture
{
	void			*img;
	signed int		*data;
	int				x_len;
	int				y_len;
}					t_texture;

typedef struct	s_cam
{
	t_vec3		pos;
	t_vec3		dir;//vec D
	t_vec3		deg;
}				t_cam;

typedef struct  s_plane
{
	int8_t		type;
	t_vec3		color;
	t_num		shine;
	t_vec3		(*find_normal)(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam);
	t_vec3		(*bright_cast)(t_vec3, t_vec3, t_vec3, t_num);
	t_vec3      coords;//произв точка на пл-ти
	t_vec3		norm;//нормаль к плоскости
    t_num       dist;//кратчайшее расстояние до плоскости
}				t_plane;

typedef struct  s_sphere
{
	int8_t		type;
	t_vec3		color;
	t_num		shine;
	t_vec3		(*find_normal)(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam);
	t_vec3		(*bright_cast)(t_vec3, t_vec3, t_vec3, t_num);
	t_vec3      coords;//центр
	t_num       rad;
}				t_sphere;

typedef struct  s_cone
{
	int8_t		type;
	t_vec3		color;
	t_num		shine;
	t_vec3		(*find_normal)(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam);
	t_vec3		(*bright_cast)(t_vec3, t_vec3, t_vec3, t_num);
	t_vec3		coords;//центр
	t_vec3		dir_vec;//вектор направления конуса
	t_num		tg;//тангенс от 1/2 угла расширения конуса
}				t_cone;

typedef struct  s_limcone//огранич. конус
{
	int8_t		type;
	t_vec3		color;
	t_num		shine;
	t_vec3		(*find_normal)(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam);
	t_vec3		(*bright_cast)(t_vec3, t_vec3, t_vec3, t_num);
	t_vec3		coords;//центр
	t_vec3		dir_vec;//вектор направления конуса
	t_num		tg;//тангенс от 1/2 угла расширения конуса
	t_num		min;//нижняя граница
	t_num		max;//верхняя граница
}				t_limcone;

typedef struct	s_cylinder
{
	int8_t		type;
	t_vec3		color;
	t_num		shine;
	t_vec3		(*find_normal)(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam);
	t_vec3		(*bright_cast)(t_vec3, t_vec3, t_vec3, t_num);
	t_vec3		coords;//произв. точка на оси цилиндра
	t_vec3		dir_vec;//напр цилиндра
	t_num		rad;
}				t_cylinder;

typedef struct	s_limcylinder
{
	int8_t		type;
	t_vec3		color;
	t_num		shine;
	t_vec3		(*find_normal)(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam);
	t_vec3		(*bright_cast)(t_vec3, t_vec3, t_vec3, t_num);
	t_vec3		max;//произв. точка на оси цилиндра
	t_vec3		dir_vec;//напр цилиндра
	t_num		rad;
}				t_limcylinder;

typedef struct	s_light
{
	int8_t				type;
	t_vec3				color;
	t_vec3				coord;
	t_num				light_pov;
	struct	s_light		*next;
	//smth else coming
}				t_light;

struct	s_obj
{
	int8_t		type;
	t_vec3		color;
	t_num		shine;
	t_vec3		(*find_normal)(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam);
	t_vec3		(*bright_cast)(t_vec3, t_vec3, t_vec3, t_num);
};

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			sl;
	int			endn;
}				t_mlx;

typedef struct	s_data
{
	char		texture_my_sphere;
	t_texture	sphere_texture;
	t_light		*light;
	t_list		*objs;
	t_cam		cam;
	t_num		(*find_destination[OBJ_COUNT])(struct s_data *, t_obj *, t_vec3 *, t_vec3 *);
//	t_vec3		(*find_normal[OBJ_COUNT])(t_obj *, t_vec3 *d, t_vec3 p);
	t_mlx		mlx;
}				t_data;

typedef struct	s_parse
{
	char		*gnl_str;
	char		gnl_flag;
	t_list		*curr_obj;
	t_light		*light;
	int			fd;
}				t_parse;

typedef struct	s_trace
{
	t_vec3		d;
	t_num		min_dist;
	t_vec3		p;
	t_vec3		normal;
	t_vec3		obj_col;
}				t_trace;

/*
**		simple error management
*/

int		safe_call_int_parse(int res, char *message, t_data *data, t_parse *parse);
void	*safe_call_ptr_parse(void *res, char *message, t_data *data, t_parse *parse);
void	remove_parse(t_parse *parse);

/*
**		parse
*/

void	parse(char *str, t_data *data);
void	parse_figure(int obj_type, t_data *data, t_parse *parse);
int		parse_light(t_data *data, t_parse *parse);
int		parse_camera(t_data *data, t_parse *parse);
int		parse_plane(t_obj **obj, t_data *data, t_parse *parse);
int		parse_sphere(t_obj **obj, t_data *data, t_parse *parse);
int		parse_cone(t_obj **obj, t_data *data, t_parse *parse);
int		parse_cylinder(t_obj **obj, t_data *data, t_parse *parse);

/*
**		parse tools
*/

void	check_error(char gnl_read_flag, char brackets, t_data *data);
int		check_line(char *should_be, char *check);
char	*parse_t_num(char *str, t_num *box);
char	*skip_to(char *check, char *original);
void	parse_vec3(char *flag_str, t_vec3 *coordinates, t_data *data, t_parse *parse);
int		parse_t_num_param(char *check, t_num *box, t_parse *parse);
int		parse_coordinates(char *str, t_vec3 *coordinates, t_data *data, t_parse *parse);
int		parse_color(char *str, t_vec3 *color, t_data *data, t_parse *parse);

/*
**		figure_cast_formulas.c
*/

t_num		sphere_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *p);
t_num		cone_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *p);
t_num		plane_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *p);
t_num		cylinder_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *p);

/*
**		figure_normals.c
*/

t_vec3		sphere_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam);
t_vec3		plane_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam);
t_vec3		cone_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam);
t_vec3		cylinder_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam);


/*
**		draw loop
*/

void		draw_figure(int x, int y, t_data *data);

/*
**		find_color.c
*/

t_vec3		curr_color(t_obj *obj, t_trace trace, t_light *light, t_data *data);
int			vec3_to_color(t_vec3 vec);
t_vec3		bright_cast2(t_vec3 light_col, t_vec3 l, t_vec3 normal, t_num shine);
t_vec3		bright_cast(t_vec3 light_col, t_vec3 l, t_vec3 normal, t_num shine);
t_vec3		bright_cast3(t_vec3 light_col, t_vec3 l, t_vec3 normal, t_num shine);

/*
**		init_data.c
*/

void	init_data(t_data *data);
t_mlx	init_mlx();

/*
**		safe_call.c
*/

int		safe_call_int(int res, char *message, t_data *data);
void	*safe_call_ptr(void *res, char *message, t_data *data);
void	remove_data(t_data *data);

/*
**		update_screen.c
*/

void		update_screen(t_data *data);

/*
**		texturing_sphere.c
*/

t_vec3		find_textel(t_data *data, t_vec3 d, t_num t, t_obj *obj);
void		load_text(t_data *data);

# endif
