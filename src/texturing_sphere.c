//
// Created by Hugor Chau on 10/21/20.
//

#include "rtv1.h"

void		load_text(t_data *data)
{
	int			endn;
	int			bpp;
	int			extra;

	if ((data->sphere_texture.img = mlx_xpm_file_to_image(data->mlx.mlx,
													   "./12.xpm", &(data->sphere_texture.x_len), &((data->sphere_texture.y_len)))) == NULL)
		exit (0);
	data->sphere_texture.data = (int *)mlx_get_data_addr((char *)(data->sphere_texture.img),
													  &bpp,
													  &extra,
													  &endn);
}

t_vec3		find_textel(t_data *data, t_vec3 d, t_num t, t_obj *obj)
{
	float		u;
	float		v;
	int			col_res;
	t_vec3		obj_col;
	int			u_res;
	int			v_res;

	if (obj->type != SPHERE)
		return (obj->color);
	d = vec3_div_num(vec3_minus(d, ((t_sphere *)obj)->coords), ((t_sphere *)obj)->rad);
	u = 0.5 + atan2(d.z, d.x) / (M_PI * 2.0);
	v = 0.5 + asin(d.y) / M_PI;
	u_res = (data->sphere_texture.x_len * u * 6);
	v_res = (data->sphere_texture.y_len * v * 3);
	if (u_res < 0)
		u_res = 0;
	v_res %= data->sphere_texture.y_len - 1;
	u_res %= data->sphere_texture.x_len - 1;
	if (v_res < 0)
		v_res = 0;
	col_res = (data->sphere_texture.data[u_res + v_res * data->sphere_texture.x_len]);
	obj_col.x = ((float)((col_res & 0x00FF0000) >> 16) / 255.0);
	obj_col.y = ((float)((col_res & 0x0000FF00) >> 8) / 255.0);
	obj_col.z = ((float)((col_res & 0x000000FF)) / 255.0);
	obj_col.x = obj_col.x < 0 ? 0 : obj_col.x > 1 ? 1 : obj_col.x;
	obj_col.y = obj_col.y < 0 ? 0 : obj_col.y > 1 ? 1 : obj_col.y;
	obj_col.z = obj_col.z < 0 ? 0 : obj_col.z > 1 ? 1 : obj_col.z;
	return (obj_col);
}
