/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:34:37 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/15 14:36:21 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void	print_path_tab(t_data *data)
{
	int i;

	i = 0;
	while (i < P1->size_path[0] + 1)
	{
		ft_printf("{magenta}|%s|{reset}-", ROOMS[P1->path_tab[0][i]]->name);
		i++;
	}
}

void	print_path_list(t_data *data)
{
	t_path	*path;
	int		i;
	int		j;

	i = 0;
	path = P1->next;
	ft_printf("{green}nb_path = %d{reset}\n", path->nb_path);
	while (i < path->nb_path)
	{
		j = 0;
		ft_printf("{red}PATH N(%d) : ", i + 1);
		ft_printf("ant_nb = %d, ", path->ant_per_path[i]);
		ft_printf("size du path %d = %d\n", i, path->size_path[i]);
		while (j <= path->size_path[i])
		{
			ft_printf("{blue}|%s|{reset}-", ROOMS[path->path_tab[i][j]]->name);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_tuboard(t_data *data, int o)
{
	int i;
	int j;

	i = -1;
	while (o == 1 && ++i < SIZE)
	{
		j = -1;
		ft_printf("{blue}Salle N° [{green}%d{blue}] : {%s}%s \t", i,
				ROOMS[i]->red ? "red" : "green", ROOMS[i]->name);
		while (++j < SIZE && TUBOARD[i][j] != INTMIN)
			ft_printf("{magenta}%d ", TUBOARD[i][j]);
		ft_printf("\n{reset}");
	}
	while (o == 2 && ++i < SIZE)
	{
		j = -1;
		ft_printf("{blue}Salle N° [{green}%d{blue}] : {green}%s \t", i,
				ROOMS[i]->name);
		while (++j < SIZE && DIS_TUBOARD[i][j] != INTMIN)
			ft_printf("{magenta}%d ", DIS_TUBOARD[i][j]);
		ft_printf("\n{reset}");
	}
}
