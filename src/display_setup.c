/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:22:20 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/12 17:44:07 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "display.h"
#include "libft.h"
#include <stdlib.h>

char	*get_data_ptr(void *img_ptr)
{
	char	*data_ptr;
	int		bit_pp;
	int		size_line;
	int		endian;

	data_ptr = mlx_get_data_addr(img_ptr, &bit_pp, &size_line, &endian);
	return (data_ptr);
}

int		get_xpm_data(t_mlx *mlx)
{
	int		a;
	int		b;
	char	*path;

	path = mlx->data->path;
	ft_strcpy(path + mlx->data->path_size, "img/PoutineLaFourmi60.xpm");
	if (!(mlx->xpm_tab = mlx_xpm_file_to_image(mlx->mlx, path, &a, &b)))
		return (0);
	mlx->data_ant = get_data_ptr(mlx->xpm_tab);
	ft_strcpy(path + mlx->data->path_size, "img/russian_flag2.xpm");
	if (!(mlx->bg_xpm = mlx_xpm_file_to_image(mlx->mlx, path, &a, &b)))
		return (0);
	mlx->bg_data = get_data_ptr(mlx->bg_xpm);
	return (1);
}

int		make_display_tuboard(t_data *data)
{
	int		i;
	int		j;

	if (!(DIS_TUBOARD = (int**)malloc(sizeof(int*) * SIZE)))
		return (0);
	i = -1;
	while (++i < SIZE)
	{
		if (!(DIS_TUBOARD[i] = (int*)malloc(sizeof(int) * SIZE)))
		{
			while (--i >= 1)
				ft_memdel((void**)&DIS_TUBOARD[i], 0);
			ft_memdel((void**)&DIS_TUBOARD, 0);
			return (free_data(data));
		}
		j = -1;
		while (++j < SIZE)
		{
			DIS_TUBOARD[i][j] = TUBOARD[i][j];
			if (DIS_TUBOARD[i][j] == INTMIN)
				break ;
		}
	}
	return (1);
}

int		clear_image(t_mlx *mlx)
{
	int i;
	int j;
	int *data;

	data = (int *)mlx->data_img;
	j = -1;
	while (++j < WIN_HGT)
	{
		i = -1;
		while (++i < WIN_LEN)
			data[j * WIN_LEN + i] = 0xFF000000;
	}
	return (1);
}
