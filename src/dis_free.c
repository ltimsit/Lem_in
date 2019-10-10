/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:20:23 by abinois           #+#    #+#             */
/*   Updated: 2019/08/12 15:37:10 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

int		free_display(t_mlx *mlx)
{
	int		i;

	if (mlx->bg_xpm)
		mlx_destroy_image(mlx->mlx, mlx->bg_xpm);
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->xpm_tab)
		mlx_destroy_image(mlx->mlx, mlx->xpm_tab);
	i = -1;
	while (++i < mlx->P1->next->nb_path && mlx->b_tab)
	{
		if (mlx->b_tab[i][0].img_rot)
			mlx_destroy_image(mlx->mlx, mlx->b_tab[i][0].img_rot);
		ft_memdel((void**)&(mlx->b_tab[i]), 0);
	}
	ft_memdel((void**)&(mlx->b_tab), 0);
	ft_memdel((void**)&(mlx->mlx), 0);
	return (0);
}

int		exit_display(t_mlx *mlx)
{
	free_display(mlx);
	free_data(mlx->data);
	exit(0);
	return (0);
}
