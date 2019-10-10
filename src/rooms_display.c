/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:40:38 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/12 18:31:24 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "display.h"
#include "libft.h"

int		coord_to_room(t_mlx *mlx, int x, int y)
{
	int	i;

	i = 0;
	while (i < mlx->SIZE)
	{
		if (ft_abs(mlx->data->rooms[i]->mlx_x - x) < 10
				&& ft_abs(mlx->data->rooms[i]->mlx_y - y) < 10)
			return (i);
		i++;
	}
	return (-1);
}

void	print_name_room(t_data *data, t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		mlx_string_put(mlx->mlx, mlx->win, ROOMS[i]->mlx_x - 4,
				ROOMS[i]->mlx_y - 11, NAME_COLOR, ROOMS[i]->name);
		i++;
	}
}

int		set_rooms(t_data *data, t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		ROOMS[i]->mlx_x = 100 + ((i % mlx->div) * mlx->of_x);
		ROOMS[i]->mlx_y = 100 + ((i / mlx->div) * mlx->of_y);
		i++;
	}
	return (1);
}

int		display_room(t_mlx *mlx, int x, int y, int color)
{
	int	*data;
	int	i;
	int	j;

	data = (int *)mlx->data_img;
	j = y >= 30 ? y - 10 : 20;
	while (j < (y + 10 >= WIN_HGT - 20 ? WIN_HGT - 20 : y + 10))
	{
		i = x >= 30 ? x - 10 : 20;
		while (i < (x + 10 >= WIN_LEN - 20 ? WIN_LEN - 20 : x + 10))
		{
			data[j * WIN_LEN + i] = color;
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}
