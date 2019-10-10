/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:59:43 by abinois           #+#    #+#             */
/*   Updated: 2019/08/10 13:15:04 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft.h"

#define PSIZE path->size_path
#define PAPP path->ant_per_path
#define NPATH path->nb_path

int		check_nb_round(t_data *data, t_path *path, int ant)
{
	int		j;
	int		round;
	int		ofset;
	int		size_tot;
	bool	lastround;

	round = 0;
	size_tot = 0;
	j = 0;
	while (j < NPATH)
		size_tot += PSIZE[j++];
	ofset = (ant + size_tot) % NPATH;
	if ((round = (ant + size_tot) / NPATH - 1 + (ofset ? 1 : 0)) > data->round)
		return (INTMAX);
	j = -1;
	round -= ofset ? 1 : 0;
	lastround = ofset ? true : false;
	while (++j < NPATH)
	{
		if ((PAPP[j] = round - PSIZE[j] + 1 + (ofset > 0 ? 1 : 0)) <= 0)
			return (INTMAX);
		ofset--;
	}
	return (lastround ? round + 1 : round);
}

int		init_path_12(t_data *data)
{
	if (!(P1 = (t_path *)malloc(sizeof(t_path))))
		return (0);
	P1->size_path = NULL;
	P1->ant_per_path = NULL;
	P1->path_tab = NULL;
	P1->nb_path = 1;
	P1->id = 1;
	if (!(P2 = (t_path *)malloc(sizeof(t_path))))
	{
		ft_memdel((void**)&P1, 0);
		P1 = NULL;
		return (0);
	}
	P2->size_path = NULL;
	P2->ant_per_path = NULL;
	P2->path_tab = NULL;
	P2->id = 2;
	P2->nb_path = 2;
	P2->next = P1;
	P1->next = P2;
	return (1);
}

int		create_path_1_and_2(t_data *data)
{
	int		i;

	i = -1;
	if (!(init_path_12(data)))
		return (free_data(data));
	if (!(P1->size_path = (int *)malloc(sizeof(int) * SIZE))
			|| !(P2->size_path = (int *)malloc(sizeof(int) * SIZE))
			|| !(P1->ant_per_path = (int *)malloc(sizeof(int) * PMAX))
			|| !(P2->ant_per_path = (int *)malloc(sizeof(int) * PMAX))
			|| !(P1->path_tab = (int **)malloc(sizeof(int *) * PMAX))
			|| !(P2->path_tab = (int **)malloc(sizeof(int *) * PMAX)))
		return (free_path_data(P1) + free_path_data(P2));
	while (++i < PMAX)
		if (!(P1->path_tab[i] = (int *)malloc(sizeof(int) * SIZE))
				|| !(P2->path_tab[i] = (int *)malloc(sizeof(int) * SIZE)))
			return (free_path_tab(data, i));
	return (1);
}

int		stock_path(t_data *data, t_path *path, int i)
{
	int		j;
	t_room	*room;

	room = ROOMS[SIZE - 1];
	path->size_path[i] = room->dad_ptr->dfs + 1;
	j = path->size_path[i];
	while (j >= 0)
	{
		if (room)
		{
			path->path_tab[i][j] = room->index;
			room = room->dad_ptr;
		}
		j--;
	}
	return (1);
}

int		get_max_path_nb(t_data *data)
{
	int k;

	k = 0;
	while (k < SIZE
			&& (TUBOARD[0][k] != INTMIN || TUBOARD[SIZE - 1][k] != INTMIN))
		k++;
	return (data->nb_ant < k ? data->nb_ant : k);
}
