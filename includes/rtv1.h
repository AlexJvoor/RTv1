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
	CYLINDER
}				t_type;

typedef struct  s_plane
{
	int8_t		type;
    t_vec3      coords;//произв точка на пл-ти
	t_vec3		norm;//нормаль к плоскости
}				t_plane;

typedef struct  s_sphere
{
	int8_t		type;
	t_vec3      coords;//центр
	float       rad;
}				t_spere;

typedef struct  s_cone
{
	int8_t		type;
	t_vec3		coords;//центр
	t_vec3		dir_vec;//вектор направления конуса
	float		tg;//тангенс от 1/2 угла расширения конуса
}				t_cone;

typedef struct  s_limcone//огранич. конус
{
	int8_t		type;
	t_vec3		coords;//центр
	t_vec3		dir_vec;//вектор направления конуса
	float		tg;//тангенс от 1/2 угла расширения конуса
	float		min;//нижняя граница
	float		max;//верхняя граница
}				t_limcone;

typedef struct	s_cylinder
{
	int8_t		type;
	t_vec3		coords;//произв. точка на оси цилиндра
	t_vec3		dir_vec;//напр цилиндра
	float		rad;
}				t_cylinder;

typedef struct	s_limcylinder
{
	int8_t		type;
	t_vec3		max;//произв. точка на оси цилиндра
	t_vec3		dir_vec;//напр цилиндра
	float		rad;
}				t_limcylinder;

typedef struct	s_light
{
	// int8_t		type;
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

typedef struct	s_objs
{
	t_plane			*planes;
	t_spere			*speres;
	t_cone			*cones;
	t_limcone		*lcones;
	t_cylinder		*cylinders;
	t_limcylinder	*lcylinders;
	t_light			*lights;
}				t_objs;

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
	t_mlx		mlx;
}				t_data;

# endif
