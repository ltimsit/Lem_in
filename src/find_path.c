/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:50:03 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/15 14:30:25 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		red_bfs(t_data *data, int option)
{
	int i;
	int	index;

	while (HEAD)
	{
		i = -1;
		while (++i < SIZE && TUBOARD[HEAD->index][i] != INTMIN)
			if ((index = TUBOARD[HEAD->index][i]) > 0 && index < SIZE
					&& !(!option && ROOMS[index]->red)
					&& ROOMS[index] != HEAD->dad_ptr
					&& !ROOMS[index]->seen)
			{
				if (ROOMS[index]->red)
					subtree(data, HEAD, ROOMS[index]);
				else
					enfiler(data, ROOMS[index], HEAD, 0);
				if (ROOMS[SIZE - 1]->seen)
					return (1);
			}
		HEAD = HEAD->next;
	}
	return (ROOMS[SIZE - 1]->dfs ? 1 : 0);
}

int		do_path(t_data *data, int path_num)
{
	int i;

	i = 0;
	while (i < path_num)
	{
		if (!(red_bfs(data, 0)))
			return (0);
		stock_path(data, P1, i);
		update_tuboard(data);
		refresh_rooms(data, 0);
		i++;
	}
	return (1);
}

void	path_finding(t_data *data)
{
	int i;
	int j;
	int ret;

	ret = 0;
	j = 0;
	i = 0;
	while (++j <= PMAX && ret != -1 && i <= data->round)
	{
		P1->nb_path = j;
		if (!do_path(data, j))
			break ;
		if ((i = check_nb_round(data, P1, data->nb_ant)) > data->round)
			break ;
		P1 = P1->next;
		data->round = i;
		while (j < PMAX && !(ret = check_for_cut(data)))
			if (!add_path(data, &i, ++j))
				break ;
	}
	if (print_input(data))
		result(data, P1->next, 1, 0);
}
