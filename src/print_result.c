/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:12:44 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/08 15:26:46 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

#define A abc[0]
#define B abc[1]
#define C abc[2]

void	get_round(t_data *data, char *buf, int *ibuf, int path_nb)
{
	t_path	*path;
	int		*path_tab;
	int		i;

	path = P1->next;
	path_tab = path->path_tab[path_nb];
	i = path->size_path[path_nb];
	while (i >= 0)
	{
		if (ROOMS[path_tab[i]]->ant_num)
		{
			strcat_lemin(buf, "L", ibuf, NULL);
			itobuf(ROOMS[path_tab[i]]->ant_num, buf, ibuf);
			strcat_lemin(buf, "-", ibuf, NULL);
			strcat_lemin(buf, ROOMS[path_tab[i]]->name, ibuf, NULL);
			strcat_lemin(buf, " ", ibuf, NULL);
			if (i == path->size_path[path_nb])
				ROOMS[path_tab[i]]->ant_num = 0;
		}
		i--;
	}
}

int		print_input(t_data *data)
{
	write(1, data->input, data->len_input);
	if (data->round == 2147483647)
		return (0);
	else
	{
		ft_putchar('\n');
		return (1);
	}
}

void	result(t_data *data, t_path *path, int ant_num, int ibuf)
{
	int		abc[3];
	int		curr_num;
	char	buffer[BUF_WRITE];

	C = -1;
	while (++C < data->round)
	{
		B = -1;
		while (++B < path->nb_path)
		{
			A = path->size_path[B];
			while (--A > 0)
				if ((curr_num = ROOMS[path->path_tab[B][A]]->ant_num))
				{
					ROOMS[path->path_tab[B][A + 1]]->ant_num = curr_num;
					ROOMS[path->path_tab[B][A]]->ant_num = 0;
				}
			if (path->ant_per_path[B]-- > 0)
				ROOMS[path->path_tab[B][1]]->ant_num = ant_num++;
			get_round(data, buffer, &ibuf, B);
		}
		buffer[ibuf - 1] = '\n';
	}
	write(1, buffer, ibuf);
}
