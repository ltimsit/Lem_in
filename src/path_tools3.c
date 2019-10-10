/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:48:43 by abinois           #+#    #+#             */
/*   Updated: 2019/08/15 14:28:49 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	subqueue(t_room *room, t_room *tail, t_room *head)
{
	room->seen = true;
	room->dfs = head->dfs + 1;
	room->dad_ptr = head;
	tail->next = room;
	tail = room;
}

void	chain(t_data *data, t_room *room, int jump)
{
	int		j;
	int		i;
	t_room	*head;
	t_room	*tail;

	head = room;
	tail = room;
	while (head)
	{
		j = -1;
		while (++j < SIZE && TUBOARD[head->index][j] != INTMIN)
			if ((i = TUBOARD[head->index][j]) > 0 && i < SIZE
				&& !ROOMS[i]->red
				&& !ROOMS[i]->seen)
			{
				ROOMS[i]->dad_red = head->red ? true : false;
				if ((head->red ? head->dfs_red + 1 : head->dfs + 1)
					== room->dfs_red + jump)
					enfiler(data, ROOMS[i], head, 0);
				else
					subqueue(ROOMS[i], tail, head);
			}
		head = head->next;
	}
}

void	subtree(t_data *data, t_room *room, t_room *son)
{
	int		i;
	int		jump;
	t_room	*cur;
	int		index;

	jump = 0;
	index = 0;
	i = -1;
	enfiler(data, son, room, 2);
	cur = son;
	while (++i < SIZE && TUBOARD[cur->index][i] != INTMIN)
		if ((index = TUBOARD[cur->index][i]) < 0
			&& !ROOMS[-index]->dad_ptr_red)
		{
			enfiler(data, ROOMS[-index], cur, !jump ? 1 : 3);
			jump++;
			cur = ROOMS[-index];
			chain(data, cur, jump);
			i = -1;
		}
}

void	tuboard_cut(t_data *data, t_room *room)
{
	int i;
	int cut1;
	int cut2;

	i = -1;
	cut1 = 0;
	cut2 = 0;
	while (++i < SIZE && (!(cut1) || !(cut2)))
	{
		if (TUBOARD[RINDEX][i] == REDADINDEX + SIZE && !cut1++)
			TUBOARD[RINDEX][i] = INTMAX;
		if (TUBOARD[REDADINDEX][i] == -RINDEX && !cut2++)
			TUBOARD[REDADINDEX][i] = INTMAX;
	}
}
