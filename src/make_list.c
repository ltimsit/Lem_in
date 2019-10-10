/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:14:42 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/05 17:47:01 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

t_room		*free_list(t_room *head)
{
	t_room	*tmp;

	while (head)
	{
		tmp = head->next;
		if (head->name)
			ft_memdel((void**)&head->name, 0);
		ft_memdel((void**)&head, 0);
		head = tmp;
	}
	return (NULL);
}

void		reset_room(t_room *newroom)
{
	newroom->name = NULL;
	newroom->next = NULL;
	newroom->start = false;
	newroom->end = false;
	newroom->red = false;
	newroom->seen = false;
	newroom->dfs = 0;
	newroom->dfs_red = 0;
	newroom->dad_ptr = NULL;
	newroom->dad_ptr_red = NULL;
	newroom->dad_red = false;
	newroom->ant_num = 0;
}

t_room		*lst_add_room(t_data *data, t_room *newroom)
{
	if (!HEAD)
		HEAD = newroom;
	else
		data->room->next = newroom;
	return (newroom);
}

t_room		*list_room_new(char *name, size_t name_size, t_data *data)
{
	t_room	*newroom;

	if (!(newroom = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	reset_room(newroom);
	if (data->next_start == 1 && (newroom->start = true))
		(data->next_start)++;
	if (data->next_end == 1 && (newroom->end = true))
		(data->next_end)++;
	if (name)
	{
		if (!(newroom->name = (char *)malloc(sizeof(char) * name_size + 1)))
		{
			ft_memdel((void**)&newroom, 0);
			return (free_list(HEAD));
		}
		newroom->name = ft_memcpy(newroom->name, name, name_size);
		newroom->name[name_size] = '\0';
	}
	else
		newroom->name = NULL;
	return (lst_add_room(data, newroom));
}
