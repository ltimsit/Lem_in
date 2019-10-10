/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:59:18 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/13 15:36:34 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include <math.h>

void	print_ant(t_mlx *mlx, char *line, int i, int k)
{
	int cpt;

	cpt = 0;
	while (cpt < mlx->SIZE
		&& ft_strcmp(line + i + k + 1, mlx->ROOMS[cpt]->name))
		cpt++;
	mlx_string_put(mlx->mlx, mlx->win, mlx->ROOMS[cpt]->mlx_x,
			mlx->ROOMS[cpt]->mlx_y + 10, 0x00FF00, line + i);
}

int		init_rotate_img(t_mlx *mlx, t_bresen *b_tab)
{
	if (!(b_tab[0].img_rot))
	{
		if (!(b_tab[0].img_rot = mlx_new_image(mlx->mlx, 86, 86)))
			return (exit_display(mlx));
		b_tab[0].data_rot = get_data_ptr(b_tab[0].img_rot);
	}
	return (1);
}

int		clear_rot_img(int *rot)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 86)
	{
		j = -1;
		while (++j < 86)
			rot[i * 86 + j] = 0xFF000000;
	}
	return (1);
}

int		create_rotated_img(t_mlx *mlx, double angle, int *rot)
{
	double	xy[2];
	int		*ant;
	int		xp;
	int		yp;

	ant = (int *)mlx->data_ant;
	clear_rot_img(rot);
	xy[1] = -31;
	while (++(xy[1]) < 30)
	{
		*xy = -31;
		while (++(xy[0]) < 30)
		{
			xp = (int)(*xy * cos(angle) + xy[1] * sin(angle));
			yp = (int)(-*xy * sin(angle) + xy[1] * cos(angle));
			rot[(yp + 43) * 86 + (xp + 43)] =
				ant[(int)((xy[1] + 30) * 60 + (*xy + 30))];
		}
	}
	return (1);
}
