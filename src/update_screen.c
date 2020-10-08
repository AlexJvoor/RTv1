#include "rtv1.h"

void		update_screen(t_data *data)
{
	int		x;
	int		y;

	y = -H_HEIGHT;
	while (y < H_HEIGHT)
	{
		x = -H_WIDTH;
		while (x < H_WIDTH)//TODO define HEIGHT / 2 && WIDTH /
		{
			draw_figure(x, y, data);
			x++;
		}
		y++;
	}
}
