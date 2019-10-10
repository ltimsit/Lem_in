/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:12:00 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/13 15:20:06 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <math.h>

int			get_ofsets(t_data *data, t_mlx *mlx)
{
	int i;

	i = SIZE;
	mlx->of_x = (WIN_LEN - 200) / mlx->div;
	mlx->of_y = (WIN_HGT - 200) / mlx->div;
	return (1);
}

void		draw_tubes(t_data *data, t_mlx *mlx)
{
	int		i;
	int		j;
	int		id;
	int		color;

	color = TUBE_COLOR;
	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
			if ((id = DIS_TUBOARD[i][j]) == -2147483648)
				break ;
			else
				init_bresen(mlx, ROOMS[i], ROOMS[id], color);
	}
}

int			draw_path(t_mlx *mlx, t_bresen **b_tab)
{
	int i;
	int	j;
	int speed;

	i = 0;
	speed = 0;
	j = -1;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg_xpm, 0, 0);
	while (++j < mlx->P1->next->nb_path)
	{
		speed = 0;
		while (speed++ < mlx->speed)
			i += bresen_path(b_tab[j], (int *)mlx->data_img, j * 100, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->win, b_tab[j][0].img_rot,
				b_tab[j][0].ax - 40, b_tab[j][0].ay - 40);
	}
	return (i);
}

double		get_angle(t_bresen *b_tab)
{
	double	ret;
	int		dx;
	int		dy;

	ret = 0.0;
	dx = b_tab[0].bx - b_tab[0].ax;
	dy = b_tab[0].by - b_tab[0].ay;
	ret = (double)dy / (double)dx;
	if (dx)
		b_tab[0].angle = atan(ret) + (dx > 0 ? 1.57 : -1.57);
	else
		b_tab[0].angle = dy <= 0 ? 0 : 3.14;
	return (b_tab[0].angle);
}

int			print_all(t_mlx *mlx)
{
	int			i;
	int			color;

	if (!mlx->play)
	{
		clear_image(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg_xpm, 0, 0);
		draw_tubes(mlx->data, mlx);
	}
	else if (mlx->play && !draw_path(mlx, (mlx->b_tab)))
		if (!(init_draw_path(mlx, (mlx->b_tab), mlx->cpt++)))
			mlx->play = 0;
	i = -1;
	while (++i < mlx->SIZE)
	{
		color = ROOM_COLOR;
		color = !i ? START_COLOR : color;
		color = i == mlx->SIZE - 1 ? END_COLOR : color;
		display_room(mlx, mlx->ROOMS[i]->mlx_x, mlx->ROOMS[i]->mlx_y, color);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	print_name_room(mlx->data, mlx);
	return (1);
}
