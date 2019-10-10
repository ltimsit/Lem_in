/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:52:23 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/15 14:38:13 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <stdlib.h>

void	parse_line(char *line, t_mlx *mlx)
{
	t_data	*data;
	int		i;
	int		j;
	int		k;

	data = mlx->data;
	i = 0;
	while (line[i])
	{
		j = 0;
		k = 0;
		while (line[i] && line[i] != 'L')
			i++;
		while (line[i + k] != '-')
			k++;
		line[i + k] = '\0';
		while (line[i + k + 1 + j] && line[i + k + 1 + j] != ' ')
			j++;
		line[i + k + 1 + j] = '\0';
		print_ant(mlx, line, i, k);
		i = i + k + 2 + j;
	}
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->mouse_room != -1)
	{
		if (x < WIN_LEN - 30)
			mlx->data->rooms[mlx->mouse_room]->mlx_x = x < 30 ? 30 : x;
		else
			mlx->data->rooms[mlx->mouse_room]->mlx_x = WIN_LEN - 30;
		if (y < WIN_HGT - 30)
			mlx->data->rooms[mlx->mouse_room]->mlx_y = y < 30 ? 30 : y;
		else
			mlx->data->rooms[mlx->mouse_room]->mlx_y = WIN_HGT - 30;
	}
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (button == 1 && !mlx->play)
		mlx->mouse_room = coord_to_room(mlx, x, y);
	return (0);
}

int		mouse_release(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 1)
		if (mlx->mouse_room != -1)
			mlx->mouse_room = -1;
	return (0);
}

int		key_press(int keycode, t_mlx *dis)
{
	if (keycode == 126 && dis->speed < 25)
		dis->speed++;
	if (keycode == 125 && dis->speed > 1)
		dis->speed--;
	if (keycode == 53)
		exit_display(dis);
	if (keycode == 49 && dis->data->round != 2147483647)
	{
		init_draw_path(dis, dis->b_tab, 0);
		dis->play = dis->play == 1 ? 0 : 1;
		dis->cpt = 1;
	}
	return (0);
}
