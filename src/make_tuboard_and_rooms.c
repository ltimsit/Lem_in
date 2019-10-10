/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuboard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:47:02 by abinois           #+#    #+#             */
/*   Updated: 2019/08/12 12:58:30 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft.h"

int		room_nbr(t_data *data)
{
	t_room	*tmp;
	int		size;

	if (!(tmp = HEAD))
		return (0);
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int		make_tuboard(int size, t_data *data)
{
	int		i;
	int		j;

	if (!(TUBOARD = (int**)malloc(sizeof(int*) * size)))
		return (0);
	i = -1;
	while (++i < size)
	{
		if (!(TUBOARD[i] = (int*)malloc(sizeof(int) * size)))
		{
			while (--i >= 0)
				ft_memdel((void**)&TUBOARD[i], 0);
			ft_memdel((void**)&TUBOARD, 0);
			return (free_data(data));
		}
		j = -1;
		while (++j < SIZE)
			TUBOARD[i][j] = INTMIN;
	}
	return (1);
}

void	clean_next_and_get_index(t_data *data, int size)
{
	int i;

	i = -1;
	while (++i < size)
	{
		ROOMS[i]->next = NULL;
		ROOMS[i]->index = i;
	}
}

int		make_rooms(int size, t_data *data)
{
	t_room	*tmp;
	int		j;

	if (!(ROOMS = (t_room **)malloc(sizeof(t_room *) * size)))
		return ((int)free_list(HEAD));
	tmp = HEAD;
	j = 1;
	while (tmp)
	{
		if (tmp->start)
			ROOMS[0] = tmp;
		else if (tmp->end)
			ROOMS[SIZE - 1] = tmp;
		else
			ROOMS[j++] = tmp;
		tmp = tmp->next;
	}
	clean_next_and_get_index(data, size);
	data->list_on = false;
	HEAD = ROOMS[0];
	data->tail = ROOMS[0];
	HEAD->seen = true;
	HEAD->dfs = 0;
	return (1);
}
