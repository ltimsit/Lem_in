/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:05:10 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/12 17:41:06 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include <math.h>

#define B_TAB b_tab[(i + 1) * 3 + j + 1]

void	bresen_line(t_mlx *mlx, t_bresen bres)
{
	int	*data;

	data = (int *)mlx->data_img;
	while (!(bres.ax == bres.bx && bres.ay == bres.by))
	{
		if ((bres.ax >= 0 && bres.ax < WIN_LEN) &&
				(bres.ay >= 0 && bres.ay < WIN_HGT))
			data[WIN_LEN * bres.ay + bres.ax] = bres.color;
		bres.e2 = bres.delta;
		if (bres.e2 > -bres.dx)
		{
			bres.delta -= bres.dy;
			bres.ax += bres.sx;
		}
		if (bres.e2 < bres.dy)
		{
			bres.delta += bres.dx;
			bres.ay += bres.sy;
		}
	}
}

int		bresen_path(t_bresen *bres, int *data, int color, int ret)
{
	int		i;

	i = -1;
	while (++i < 9)
	{
		if (bres[i].ax == bres[i].bx && bres[i].ay == bres[i].by)
			continue ;
		if ((bres[i].ax >= 0 && bres[i].ax < WIN_LEN) &&
				(bres[i].ay >= 0 && bres[i].ay < WIN_HGT))
			data[WIN_LEN * bres[i].ay + bres[i].ax] = color;
		bres[i].e2 = bres[i].delta;
		if (bres[i].e2 > -bres[i].dx)
		{
			bres[i].delta -= bres[i].dy;
			bres[i].ax += bres[i].sx;
		}
		if (bres[i].e2 < bres[i].dy)
		{
			bres[i].delta += bres[i].dx;
			bres[i].ay += bres[i].sy;
		}
		ret = 1;
	}
	return (ret);
}

void	init_path_bresen(t_mlx *mlx, t_room *a, t_room *b, t_bresen *b_tab)
{
	int		i;
	int		j;
	double	ret;

	i = -2;
	ret = 0.0;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			B_TAB.ax = a->mlx_x + j;
			B_TAB.bx = b->mlx_x + j;
			B_TAB.ay = a->mlx_y + i;
			B_TAB.by = b->mlx_y + i;
			B_TAB.dx = ft_abs(B_TAB.ax - B_TAB.bx);
			B_TAB.dy = ft_abs(B_TAB.ay - B_TAB.by);
			B_TAB.sx = B_TAB.ax < B_TAB.bx ? 1 : -1;
			B_TAB.sy = B_TAB.ay < B_TAB.by ? 1 : -1;
			B_TAB.delta = (B_TAB.dx > B_TAB.dy ? B_TAB.dx : -B_TAB.dy) / 2;
		}
	}
	ret = get_angle(b_tab);
	init_rotate_img(mlx, b_tab);
	create_rotated_img(mlx, -b_tab[0].angle, (int *)(b_tab[0].data_rot));
}

void	init_bresen(t_mlx *mlx, t_room *a, t_room *b, int color)
{
	int			i;
	int			j;
	t_bresen	bres;

	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			bres.ax = a->mlx_x + j;
			bres.bx = b->mlx_x + j;
			bres.ay = a->mlx_y + i;
			bres.by = b->mlx_y + i;
			bres.color = color;
			bres.dx = ft_abs(bres.ax - bres.bx);
			bres.dy = ft_abs(bres.ay - bres.by);
			bres.sx = bres.ax < bres.bx ? 1 : -1;
			bres.sy = bres.ay < bres.by ? 1 : -1;
			bres.delta = (bres.dx > bres.dy ? bres.dx : -bres.dy) / 2;
			bresen_line(mlx, bres);
		}
	}
}
