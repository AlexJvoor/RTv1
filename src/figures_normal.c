//
// Created by Joseth Voor on 10/8/20.
//

#include "rtv1.h"

t_vec3		sphere_normal(t_obj *obj, t_vec3 *d, t_vec3 p)
{
	return(vec3_normalize(vec3_minus(((t_sphere *)obj)->coords, p)));
}

t_vec3		plane_normal(t_obj *obj, t_vec3 *d, t_vec3 p)
{
	return (((t_plane *)obj)->norm);
}

t_vec3		cone_normal(t_obj *obj, t_vec3 *d, t_vec3 p)
{
	return ((t_vec3){0, 0, 0});
}

t_vec3		cylinder_normal(t_obj *obj, t_vec3 *d, t_vec3 p)
{
	return ((t_vec3){0, 0, 0});
}
