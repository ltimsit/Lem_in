/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:41:48 by abinois           #+#    #+#             */
/*   Updated: 2019/08/13 15:13:25 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int		free_path_data(t_path *path)
{
	if (path)
	{
		if (path->size_path)
			ft_memdel((void**)&(path->size_path), 0);
		if (path->ant_per_path)
			ft_memdel((void**)&(path->ant_per_path), 0);
		if (path->path_tab)
			ft_memdel((void**)&(path->path_tab), 0);
		ft_memdel((void**)&path, 0);
	}
	return (0);
}

int		free_path_tab(t_data *data, int i)
{
	while (i >= 0)
	{
		if (P1)
			ft_memdel((void**)&(P1->path_tab[i]), 0);
		if (P1->next)
			ft_memdel((void**)&(P1->next->path_tab[i]), 0);
		i--;
	}
	return (P1 ? free_path_data(P1->next) + free_path_data(P1) : 0);
}

int		free_data(t_data *data)
{
	int		i;

	i = -1;
	data->fd > 0 ? close(data->fd) : 0;
	ft_get_next_line(data->fd, NULL, 1);
	if (data->list_on)
		free_list(HEAD);
	ft_memdel((void**)&(data->input), 0);
	while (++i < SIZE)
	{
		if (ROOMS)
		{
			ft_memdel((void**)&(ROOMS[i]->name), 0);
			ft_memdel((void**)&ROOMS[i], 0);
		}
		if (TUBOARD)
			ft_memdel((void**)&TUBOARD[i], 0);
		if (DIS_TUBOARD)
			ft_memdel((void**)&DIS_TUBOARD[i], 0);
	}
	ft_memdel((void**)&TUBOARD, 0);
	ft_memdel((void**)&DIS_TUBOARD, 0);
	ft_memdel((void**)&ROOMS, 0);
	free_path_tab(data, PMAX - 1);
	return (0);
}
