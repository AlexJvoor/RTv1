//
// Created by Hugor Chau on 10/6/20.
//

#include "rtv1.h"

float		sphere_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *cam)
{
	t_vec3	c = ((t_sphere *)obj)->coords;
	float	r = ((t_sphere *)obj)->rad;
	t_vec3	oc = vec3_minus(*cam, c);

	float k1 = vec3_dot(*d, *d);
	float k2 = 2 * vec3_dot(oc, *d);
	float k3 = vec3_dot(oc, oc) - r*r;
	float discriminant = k2*k2 - 4*k1*k3;
	if (discriminant < 0)
		return (INFINITY);
	float t1 = (-k2 + sqrt(discriminant)) / (2*k1);
	float t2 = (-k2 - sqrt(discriminant)) / (2*k1);
	return (t1 < t2 ? t1 : t2);
}

float		cone_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *cam)
{
	return (INFINITY);
}

float		plane_cast(t_data *data, t_obj *obj, t_vec3 *d_old, t_vec3 *cam)
{
	t_vec3 d = vec3_normalize(*d_old);
    t_plane *pl = (t_plane *)obj;
    t_vec3 n = vec3_normalize(pl->norm);
    t_vec3 c = vec3_mult_num(n, pl->dist * -1);
    t_vec3		o = *cam;
    t_vec3		x = vec3_minus(o, c);
    float dv = vec3_dot(d, n);
    if (dv == 0)
    {
		return (INFINITY);
	}
	float t = vec3_dot(vec3_invert(x), n) / dv * (-1);
	return (t);
}

float		cylinder_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *cam)
{
	//	m = (D*t+X)|V
	float		res;
	t_vec3 v = vec3_normalize(((t_cylinder*)obj)->dir_vec);
	t_vec3	oc = vec3_minus(*cam, ((t_cylinder*)obj)->coords);
	float a = vec3_dot(*d, *d) - pow(vec3_dot(*d, v), 2);
	float b = 2 * (vec3_dot(*d, oc) - vec3_dot(*d, v) * vec3_dot(oc, v));
	float c = vec3_dot(oc, oc) - pow(vec3_dot(oc, v), 2) - pow(((t_cylinder*)obj)->rad, 2);
	float discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return (INFINITY);
	float t1 = (-b + sqrt(discriminant)) / (2*a);
	float t2 = (-b - sqrt(discriminant)) / (2*a);
	res = t1 < t2 ? t1 : t2;
	if (res < 0)
		return (res);
	float mmm = vec3_dot(*d, vec3_mult_num(v, res)) + vec3_dot(oc, v);

	t_vec3 p = vec3_plus(vec3_mult_num(*d, res), data->cam.pos);

//	((t_cylinder*)obj)->normal = vec3_normalize(vec3_minus(vec3_minus(p, ((t_cylinder*)obj)->coords), vec3_mult_num(v, mmm)));
	((t_cylinder*)obj)->normal = vec3_normalize(vec3_minus(vec3_mult_num(v, mmm), vec3_minus(p, ((t_cylinder*)obj)->coords)));
	return (res);
}
