//
// Created by Joseth Voor on 10/8/20.
//

#include "rtv1.h"

t_vec3		sphere_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam)
{
	t_vec3 p = vec3_plus(vec3_mult_num(*d, min_dist), cam.pos);
	return(vec3_normalize(vec3_minus(((t_sphere *)obj)->coords, p)));
}

t_vec3		plane_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam)
{
//	if (vec3_dot(*d, ))
	return (((t_plane *)obj)->norm);
}

t_vec3		cone_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam)
{
	t_vec3	v;
	t_vec3	oc;
	t_num	m;
	t_num	k = tan((((t_cone*)obj)->tg));
	t_vec3	p;
	t_vec3	p_c;
	t_vec3	v_m;

	v = vec3_normalize(((t_cone*)obj)->dir_vec);
	oc = vec3_minus(cam.pos, ((t_cone*)obj)->coords);
//	m = vec3_dot(*d, vec3_mult_num(v, min_dist)) + vec3_dot(oc, v);
	m = vec3_dot(*d, v) * min_dist + vec3_dot(oc, v);
	v_m = vec3_mult_num(v, m);
	p = vec3_plus(cam.pos, vec3_mult_num(*d, min_dist));
	p_c = vec3_minus(p, ((t_cone*)obj)->coords);
//	return vec3_normalize(vec3_minus(vec3_minus(v_m, p_c), vec3_mult_num(v, m)));
	return vec3_normalize(vec3_minus(vec3_mult_num(v, m*(1+k*k)), p_c));//tan(tg)^2 + 1 == 1/cos(tg)^2
	//{-r*cos(angle), -r*sin(angle), r}d(r)d(angle)
	//vec3_minus(vec3_plus(), vec3_mult_num())
//	mv_minus(mv_plus(mv_mult_num(ray=v, intersect_dist=m), oc), mv_mult_num(obj.axis, (1 + k2) * m));
}

//m = vec3_dot(r.dir, cylinder.v) * t 'min_dist' + vec_dot(vec_minus(cam, cylinder.pos), cylinder.v);+++++++++++
//p = vec_add(r.start, vec_scale(r.dir, t));++++
//n = vec_norm(vec_sub(vec_sub(p, cylinder.pos), vec_scale(cylinder.v, m)));

//t_vec3		cylinder_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam)
//{
//	t_vec3	v;
//	t_vec3	oc;
//	t_num	m;
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

t_vec3		cylinder_normal(t_obj *obj, t_vec3 *d, t_num min_dist, t_cam cam)
{
	t_vec3	v;
	t_vec3	oc;
	t_num	m;
	t_vec3	p;
	t_vec3	p_c;
	t_vec3	v_m;

	v = vec3_normalize(((t_cylinder*)obj)->dir_vec);
	oc = vec3_minus(cam.pos, ((t_cylinder*)obj)->coords);
	m = vec3_dot(*d, vec3_mult_num(v, min_dist)) + vec3_dot(oc, v);
	p = vec3_plus(vec3_mult_num(*d, min_dist), cam.pos);
	p_c = vec3_minus(p, ((t_cylinder*)obj)->coords);
	v_m = vec3_mult_num(v, m);
	return vec3_normalize(vec3_minus(v_m, p_c));
//	return vec3_mult_num(vec3_normalize(vec3_minus(p_c, v_m)), -1);
}