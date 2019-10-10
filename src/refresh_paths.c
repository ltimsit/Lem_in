/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:59:43 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/15 14:28:20 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		refresh_tuboard(t_data *data, int *tuboard, int x)
{
	int		i;
	int		j;
	int		index;

	i = -1;
	while (++i < SIZE && tuboard[i] != INTMIN)
	{
		if (tuboard[i] <= 0)
		{
			tuboard[i] *= -1;
			index = tuboard[i];
			j = -1;
			while (++j < SIZE && TUBOARD[index][j] != INTMIN)
				if (TUBOARD[index][j] == x + SIZE)
				{
					TUBOARD[index][j] = x;
					break ;
				}
		}
	}
	return (1);
}

int		refresh_rooms(t_data *data, int option)
{
	int i;
	int j;

	i = -1;
	j = SIZE;
	while (++i <= --j)
	{
		if (option)
		{
			ROOMS[i]->red = false;
			refresh_tuboard(data, TUBOARD[i], i);
			ROOMS[j]->red = false;
			refresh_tuboard(data, TUBOARD[j], j);
		}
		room_refresher(ROOMS[i]);
		room_refresher(ROOMS[j]);
	}
	HEAD = ROOMS[0];
	data->tail = ROOMS[0];
	HEAD->seen = true;
	return (1);
}

int		update_tuboard(t_data *data)
{
	t_room	*room;
	int		i;
	int		ok1;
	int		ok2;

	room = ROOMS[SIZE - 1];
	while (room->dad_ptr)
	{
		i = -1;
		ok1 = 0;
		ok2 = 0;
		room->red = RINDEX == SIZE - 1 ? false : true;
		while (++i < SIZE && (!ok1 || !ok2))
		{
			if (TUBOARD[DADINDEX][i] == RINDEX && !ok1++)
				TUBOARD[DADINDEX][i] = RINDEX + SIZE;
			if (TUBOARD[RINDEX][i] == DADINDEX && !ok2++)
				TUBOARD[RINDEX][i] = -DADINDEX;
		}
		room = room->dad_ptr;
	}
	return (1);
}

int		cut(t_data *data, t_room *room, int son, int *cut_yes)
{
	if (room && room->red)
	{
		if (((!son && room->dad_ptr_red)
				|| (!room->dad_ptr && room->dad_ptr_red)) && ++(*cut_yes))
			tuboard_cut(data, room);
		if (son)
			cut(data, room->dad_ptr ? room->dad_ptr :
					room->dad_ptr_red, 1, cut_yes);
		else
			cut(data, room->dad_ptr_red, 1, cut_yes);
	}
	else if (room && room->dad_ptr)
		cut(data, room->dad_ptr, 0, cut_yes);
	return (0);
}

int		cut_edge(t_data *data)
{
	t_room	*end;
	int		i;

	i = 0;
	end = ROOMS[SIZE - 1];
	if (end->dfs)
		cut(data, end->dad_ptr, 0, &i);
	return (i);
}
