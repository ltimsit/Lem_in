/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:27:14 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/14 16:48:29 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_path(t_data *data, int *i, int j)
{
	P1->nb_path = j;
	stock_and_skip(data, P1, j - 1);
	if ((*i = check_nb_round(data, P1, data->nb_ant)) > data->round)
		return (0);
	P1 = P1->next;
	data->round = *i;
	update_tuboard(data);
	refresh_rooms(data, 0);
	return (1);
}

int		check_for_cut(t_data *data)
{
	if (!(red_bfs(data, 1)))
		return (-1);
	if (!cut_edge(data))
		return (0);
	else
		refresh_rooms(data, 1);
	return (1);
}

int		stock_and_skip(t_data *data, t_path *p1, int i)
{
	int j;
	int k;

	j = 0;
	while (j < i)
	{
		p1->size_path[j] = p1->next->size_path[j];
		k = 0;
		while (k <= p1->next->size_path[j])
		{
			p1->path_tab[j][k] = p1->next->path_tab[j][k];
			k++;
		}
		j++;
	}
	stock_path(data, p1, i);
	return (1);
}

void	room_refresher(t_room *room)
{
	room->seen = false;
	room->dfs = 0;
	room->dfs_red = 0;
	room->dad_ptr = NULL;
	room->dad_ptr_red = NULL;
	room->dad_red = false;
	room->next = NULL;
}

void	enfiler(t_data *data, t_room *room, t_room *head, int o)
{
	if (!o)
	{
		data->tail->next = room;
		data->tail = room;
		room->dad_ptr = head;
		room->dfs = head->dfs + 1;
		room->seen = true;
	}
	else if (o == 1 || o == 3)
	{
		room->dfs_red = o == 1 ? head->dfs - 1 : head->dfs_red - 1;
		room->seen = true;
		room->dad_ptr_red = head;
		room->dad_red = true;
	}
	else if (o == 2)
	{
		room->dad_ptr = head;
		room->dfs = head->dfs + 1;
		room->seen = true;
	}
}
