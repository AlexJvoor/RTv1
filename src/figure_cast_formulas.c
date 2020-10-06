//
// Created by Hugor Chau on 10/6/20.
//

#include "rtv1.h"

t_vec2		sphere_cast(t_data *data, t_obj *obj, t_vec3 *d)
{
	t_vec3	c = ((t_sphere *)obj)->coords;
	float	r = ((t_sphere *)obj)->rad;
	t_vec3	oc = vec3_minus(data->cam.pos, c);

	float k1 = vec3_dot(*d, *d);
	float k2 = 2 * vec3_dot(oc, *d);
	float k3 = vec3_dot(oc, oc) - r*r;
	float discriminant = k2*k2 - 4*k1*k3;
	if (discriminant < 0)
		return (t_vec2){INFINITY, INFINITY};
	float t1 = (-k2 + sqrt(discriminant)) / (2*k1);
	float t2 = (-k2 - sqrt(discriminant)) / (2*k1);
	return (t_vec2){t1, t2};
}

t_vec2		cone_cast(t_data *data, t_obj *obj, t_vec3 *d)
{
	return ((t_vec2){-1, -1});
}

t_vec2		plane_cast(t_data *data, t_obj *obj, t_vec3 *d)
{
	return ((t_vec2){-1, -1});
}

t_vec2		cylinder_cast(t_data *data, t_obj *obj, t_vec3 *d)
{
	return ((t_vec2){-1, -1});
}
