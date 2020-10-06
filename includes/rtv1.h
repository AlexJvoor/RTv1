#ifndef RTV1_H
# define RTV1_H
#include "stdio.h"
#include "math.h"
#include "mlx.h"
#include "libnum.h"
#include "libft.h"

#define WIDTH 1000
#define HEIGHT 1000


#define FOV 1,0472// == rads 60 | 1,5708 == rads 90

//TODO для фикса рыбьего глаза м. просчитывать каждую точку как z = sqrt(x^2 + y^2) (?возможно?)

typedef enum	e_type
{
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	LIGHT
}				t_type;

typedef struct  s_plane
{
	int8_t		type;
	t_vec3		color;
    t_vec3      coords;//произв точка на пл-ти
	t_vec3		norm;//нормаль к плоскости
    float       dist;//кратчайшее расстояние до плоскости
}				t_plane;

typedef struct  s_sphere
{
	int8_t		type;
	t_vec3		color;
	t_vec3      coords;//центр
	float       rad;
}				t_sphere;

typedef struct  s_cone
{
	int8_t		type;
	t_vec3		color;
	t_vec3		coords;//центр
	t_vec3		dir_vec;//вектор направления конуса
	float		tg;//тангенс от 1/2 угла расширения конуса
}				t_cone;

typedef struct  s_limcone//огранич. конус
{
	int8_t		type;
	t_vec3		color;
	t_vec3		coords;//центр
	t_vec3		dir_vec;//вектор направления конуса
	float		tg;//тангенс от 1/2 угла расширения конуса
	float		min;//нижняя граница
	float		max;//верхняя граница
}				t_limcone;

typedef struct	s_cylinder
{
	int8_t		type;
	t_vec3		color;
	t_vec3		coords;//произв. точка на оси цилиндра
	t_vec3		dir_vec;//напр цилиндра
	float		rad;
}				t_cylinder;

typedef struct	s_limcylinder
{
	int8_t		type;
	t_vec3		color;
	t_vec3		max;//произв. точка на оси цилиндра
	t_vec3		dir_vec;//напр цилиндра
	float		rad;
}				t_limcylinder;

typedef struct	s_light
{
	int8_t		type;
	t_vec3		coord;
	float		light_pov;
	// t_light		*next;
	//smth else coming
}				t_light;

typedef struct	s_cam
{
	t_vec3		pos;
	t_vec3		dir;//vec D
	t_vec3		deg;
}				t_cam;

typedef struct	s_obj
{
	int8_t		type;
}				t_obj;

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
	t_light		*light;
	t_list		*objs;
	t_cam		cam;
	t_vec2		(*find_destination[4])(struct s_data *, t_obj *, t_vec3 *);
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

/*
**		simple error management
*/

int		safe_call_int(int res, char *message, t_data *data);
void	*safe_call_ptr(void *res, char *message, t_data *data);
int		safe_call_int_parse(int res, char *message, t_data *data, t_parse *parse);
void	*safe_call_ptr_parse(void *res, char *message, t_data *data, t_parse *parse);

/*
**		parse
*/

void	parse(char *str, t_data *data);
int		parse_light(t_data *data, t_parse *parse);
int		parse_plane(t_data *data, t_parse *parse);
int		parse_sphere(t_data *data, t_parse *parse);
int		parse_cone(t_data *data, t_parse *parse);
int		parse_cylinder(t_data *data, t_parse *parse);

/*
**		parse tools
*/

void	check_error(char gnl_read_flag, char brackets, t_data *data);
int		check_line(char *should_be, char *check);
char	*parse_float(char *str, float *box);
char	*skip_to(char *check, char *original);
void	parse_vec3(char *str, t_vec3 *coordinates, t_data *data, t_parse *parse);

/*
**		memory management
*/

void	init_data(t_data *data);
void	remove_data(t_data *data);
t_mlx	init_mlx();

/*
**		figure cast formulas
*/

t_vec2		sphere_cast(t_data *data, t_obj *obj, t_vec3 *d);
t_vec2		cone_cast(t_data *data, t_obj *obj, t_vec3 *d);
t_vec2		plane_cast(t_data *data, t_obj *obj, t_vec3 *d);
t_vec2		cylinder_cast(t_data *data, t_obj *obj, t_vec3 *d);

/*
**		draw loop
*/

void		update_screen(t_data *data);

# endif
