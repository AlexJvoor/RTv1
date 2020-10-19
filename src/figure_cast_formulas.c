//
// Created by Hugor Chau on 10/6/20.
//

#include "rtv1.h"

t_num		sphere_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *cam)
{
	t_vec3	c = ((t_sphere *)obj)->coords;
	t_num	r = ((t_sphere *)obj)->rad;
	t_vec3	oc = vec3_minus(*cam, c);

	t_num k1 = vec3_dot(*d, *d);
	t_num k2 = 2 * vec3_dot(oc, *d);
	t_num k3 = vec3_dot(oc, oc) - r*r;
	t_num discriminant = k2*k2 - 4*k1*k3;
	if (discriminant < 0)
		return (INFINITY);
	t_num t1 = (-k2 + sqrt(discriminant)) / (2*k1);
	t_num t2 = (-k2 - sqrt(discriminant)) / (2*k1);
	return (t1 < t2 ? t1 : t2);
}

t_num		cone_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *cam)//mult len of A-P to k<-----------!!!
{
// 	t_num		res;
// 	t_vec3 v = vec3_normalize(((t_cone *)obj)->dir_vec);
	t_vec3	oc/* = vec3_minus(*cam, ((t_cone *)obj)->coords)*/;//try to rev vec !
// //	t_num 		k = pow((tan(((t_cone*)obj)->tg)), 2);

// 	t_num a = pow(vec3_dot(*d, v), 2) - pow(cos(((t_cone *)obj)->tg), 2);
// 	t_num b = 2 * ((vec3_dot(*d, v) * vec3_dot(oc, v) - vec3_dot(*d, oc)) * pow(cos(((t_cone *)obj)->tg), 2));
// 	t_num c = pow(vec3_dot(oc, v), 2) - vec3_dot(oc, oc) * pow(cos(((t_cone *)obj)->tg), 2);
	t_num				dot_ov_r;
	t_num				dot_co_r;
	t_num				k;

	// ray->cent_obj = cone.center;
	oc = vec3_minus(*cam, ((t_cone *)obj)->coords);
	dot_co_r = vec3_dot(oc, ((t_cone *)obj)->dir_vec);
	dot_ov_r = vec3_dot(*d, ((t_cone *)obj)->dir_vec);
	k = tan(0.5 * (((t_cone*)obj)->tg));
	k = k * k + 1.0;
	t_num a = vec3_dot(*d, *d) - k * pow(dot_ov_r, 2.0);
	t_num b = 2.0 * (vec3_dot(*d, oc) - k * dot_co_r * dot_ov_r);
	t_num c = vec3_dot(oc, oc) - k * pow(dot_co_r, 2.0);
	t_num discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return (INFINITY);
	t_num t1 = (-b + sqrt(discriminant)) / (2*a);
	t_num t2 = (-b - sqrt(discriminant)) / (2*a);
	if (t1 < t2 && t1 > 0)
		return (t1);
	if (t2 < t1 && t2 > 0)
		return (t2);
	return (INFINITY);
}

t_num		plane_cast(t_data *data, t_obj *obj, t_vec3 *d_old, t_vec3 *cam)
{
	t_vec3 d = vec3_normalize(*d_old);
    t_plane *pl = (t_plane *)obj;
    t_vec3 n = vec3_normalize(pl->norm);
    t_vec3 c = vec3_mult_num(n, pl->dist * -1);
    t_vec3		o = *cam;
    t_vec3		x = vec3_minus(o, c);
    t_num dv = vec3_dot(d, n);
    if (dv == 0)
    {
		return (INFINITY);
	}
	t_num t = vec3_dot(vec3_invert(x), n) / dv * (-1);
	return (t);
}

t_num		cylinder_cast(t_data *data, t_obj *obj, t_vec3 *d, t_vec3 *cam)
{
	t_num		res;
	t_vec3 v = vec3_normalize(((t_cylinder*)obj)->dir_vec);
	t_vec3	oc = vec3_minus(*cam, ((t_cylinder*)obj)->coords);
	t_num a = vec3_dot(*d, *d) - pow(vec3_dot(*d, v), 2);
	t_num b = 2 * (vec3_dot(*d, oc) - vec3_dot(*d, v) * vec3_dot(oc, v));
	t_num c = vec3_dot(oc, oc) - pow(vec3_dot(oc, v), 2) - pow(((t_cylinder*)obj)->rad, 2);
	t_num discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return (INFINITY);
	t_num t1 = (-b + sqrt(discriminant)) / (2*a);
	t_num t2 = (-b - sqrt(discriminant)) / (2*a);
	return (t1 < t2 ? t1 : t2);
}
