/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:03:25 by abinois           #+#    #+#             */
/*   Updated: 2019/08/15 14:40:24 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

int		init_draw_path(t_mlx *mlx, t_bresen **b_tab, int cur_pos)
{
	int		i;
	int		j;
	t_path	*path;
	int		color;

	path = mlx->P1->next;
	color = 0x552222;
	i = 0;
	j = -1;
	while (++j < path->nb_path)
	{
		if (cur_pos < path->size_path[j])
		{
			init_path_bresen(mlx, mlx->ROOMS[path->path_tab[j][cur_pos]],
					mlx->ROOMS[path->path_tab[j][cur_pos + 1]], b_tab[j]);
			i = 1;
		}
		color += 0x002222;
	}
	return (i);
}

int		init_b_tab(t_mlx *mlx, int size)
{
	t_bresen	**b_tab;
	int			i;

	if (!(b_tab = (t_bresen **)malloc(sizeof(t_bresen *) * size)))
		return (0);
	i = -1;
	while (++i < size)
	{
		if (!(b_tab[i] = (t_bresen *)malloc(sizeof(t_bresen) * 9)))
		{
			while (--i >= 0)
				ft_memdel((void **)&(b_tab[i]), 0);
			ft_memdel((void **)&(b_tab), 0);
			return (0);
		}
		b_tab[i][0].img_rot = NULL;
	}
	mlx->b_tab = b_tab;
	return (1);
}

int		init_mlx_struct(t_mlx *mlx, t_data *data)
{
	mlx->play = 0;
	mlx->speed = 4;
	mlx->img = NULL;
	mlx->b_tab = NULL;
	mlx->xpm_tab = NULL;
	mlx->bg_xpm = NULL;
	mlx->mouse_room = -1;
	mlx->data = data;
	mlx->div = ft_sqrtup(SIZE);
	return (1);
}

int		init_display(t_data *data)
{
	t_mlx	mlx;

	init_mlx_struct(&mlx, data);
	if (!(mlx.mlx = mlx_init()))
		return (0);
	if (!(init_b_tab(&mlx, P1->next->nb_path)))
		return (free_display(&mlx));
	mlx.win = mlx_new_window(mlx.mlx, WIN_LEN, WIN_HGT, "LEM_IN");
	if (!(mlx.img = mlx_new_image(mlx.mlx, WIN_LEN, WIN_HGT)))
		return (free_display(&mlx));
	mlx.data_img = get_data_ptr(mlx.img);
	if (!(get_xpm_data(&mlx)))
		return (free_display(&mlx));
	get_ofsets(data, &mlx);
	set_rooms(data, &mlx);
	mlx_hook(mlx.win, 4, 0, mouse_press, &mlx);
	mlx_hook(mlx.win, 5, 0, mouse_release, &mlx);
	mlx_hook(mlx.win, 6, 0, mouse_move, &mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_display, &mlx);
	mlx_loop_hook(mlx.mlx, print_all, &mlx);
	mlx_loop(mlx.mlx);
	return (1);
}
