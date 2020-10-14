/*
**		эта функция нужна только для проверки данных,
**		в готовой проге ей не быть! Поэтому не буду
**		нормить, соррян
*/

#include "rtv1.h"

/*
**			checking parsed objects
*/

void			check_data(t_data *data)
{
	t_list		*lst;

	lst = data->objs;
	while (lst)
	{
		if ((*(t_obj **)lst->content)->type == SPHERE)
		{
			printf("Type: sphere\n"
			"coordinates: %f, %f, %f\n"
			"radius: %f\n\n",
			(*(t_sphere **)lst->content)->coords.x,
			(*(t_sphere **)lst->content)->coords.y,
			(*(t_sphere **)lst->content)->coords.z,
			(*(t_sphere **)lst->content)->rad);
		}
		if ((*(t_obj **)lst->content)->type == PLANE)
		{
//			printf("Type: plane\ncoordinates: %f, %f, %f\ndistance: %f\n\n",
//				   (*(t_plane **)lst->content)->coords.x, (*(t_plane **)lst->content)->coords.y,
//				   (*(t_plane **)lst->content)->coords.z, (*(t_plane **)lst->content)->dist);
			printf("Type: plane\n"
			"coordinates: %f, %f, %f\n"
			"color: %f, %f, %f\n"
			"distance: %f\n\n",
			(*(t_plane **)lst->content)->norm.x,
			(*(t_plane **)lst->content)->norm.y,
			(*(t_plane **)lst->content)->norm.z,
				   (*(t_plane **)lst->content)->color.x,
				   (*(t_plane **)lst->content)->color.y,
				   (*(t_plane **)lst->content)->color.z,
			(*(t_plane **)lst->content)->dist);
		}
		if ((*(t_obj **)lst->content)->type == CONE)
		{
			printf("Type: cone\n"
			"coordinates: %f, %f, %f\n"
			"dir_vec: %f, %f, %f\n"
			"tangent: %f\n\n",
			(*(t_cone **)lst->content)->coords.x,
			(*(t_cone **)lst->content)->coords.y,
			(*(t_cone **)lst->content)->coords.z,
			(*(t_cone **)lst->content)->dir_vec.x,
			(*(t_cone **)lst->content)->dir_vec.y,
			(*(t_cone **)lst->content)->dir_vec.z,
			(*(t_cone **)lst->content)->tg);
		}
		if ((*(t_obj **)lst->content)->type == CYLINDER)
		{
			printf("Type: cylinder11111\n"
			"coordinates: %f, %f, %f\n"
			"dir_vec: %f, %f, %f\n"
   			"radius: %f\n\n",
			(*(t_cylinder **)lst->content)->coords.x,
			(*(t_cylinder **)lst->content)->coords.y,
			(*(t_cylinder **)lst->content)->coords.z,
			(*(t_cylinder **)lst->content)->dir_vec.x,
			(*(t_cylinder **)lst->content)->dir_vec.y,
			(*(t_cylinder **)lst->content)->dir_vec.z,
			(*(t_cylinder **)lst->content)->rad);
		}
		lst = lst->next;
	}
}
