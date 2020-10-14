//
// Created by Joseth Voor on 10/8/20.
//

#include "rtv1.h"

t_vec3		sphere_normal(t_obj *obj, t_vec3 *d, float min_dist, t_cam cam)
{
	t_vec3 p = vec3_plus(vec3_mult_num(*d, min_dist), cam.pos);
	return(vec3_normalize(vec3_minus(((t_sphere *)obj)->coords, p)));
}

t_vec3		plane_normal(t_obj *obj, t_vec3 *d, float min_dist, t_cam cam)
{
	return (((t_plane *)obj)->norm);
}

t_vec3		cone_normal(t_obj *obj, t_vec3 *d, float min_dist, t_cam cam)
{
	return ((t_vec3){0, 0, 0});
}

//t_vec3		cylinder_normal(t_obj *obj, t_vec3 *d, float min_dist, t_cam cam)
//{
//	t_vec3	v;
//	t_vec3	oc;
//	float	m;
//	t_vec3	p;
////	t_vec	p_c;
////	t_vec3	v_m;
//
//	v = vec3_normalize(((t_cylinder*)obj)->dir_vec);
//	oc = vec3_minus(cam.pos, ((t_cylinder*)obj)->coords);
//	m = vec3_dot(*d, vec3_mult_num(v, min_dist)) + vec3_dot(oc, v);
////	v_m = vec3_mult_num(v, m);
////	p_c = vec3_minus(p, ((t_cylinder*)obj)->coords));
//	p = vec3_plus(vec3_mult_num(*d, min_dist), cam.pos);
//	return vec3_normalize(vec3_minus(vec3_mult_num(v, m), vec3_minus(p, ((t_cylinder*)obj)->coords)));
//}


t_vec3		cylinder_normal(t_obj *obj, t_vec3 *d, float min_dist, t_cam cam)
{
	t_vec3	v;
	t_vec3	oc;
	float	m;
	t_vec3	p;
	t_vec3	p_c;
	t_vec3	v_m;

	v = vec3_normalize(((t_cylinder*)obj)->dir_vec);
	oc = vec3_minus(cam.pos, ((t_cylinder*)obj)->coords);
	m = vec3_dot(*d, vec3_mult_num(v, min_dist)) + vec3_dot(oc, v);
	p = vec3_plus(vec3_mult_num(*d, min_dist), cam.pos);
	p_c = vec3_minus(p, ((t_cylinder*)obj)->coords);
	v_m = vec3_mult_num(v, m);
//	return vec3_normalize(vec3_minus(v_m, p_c));
	return vec3_normalize(vec3_minus(v_m, p_c));
}