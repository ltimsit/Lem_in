/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:08:33 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/15 17:24:43 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		add_tube(t_data *data, int s1, int s2)
{
	int		i;
	int		s1ok;
	int		s2ok;

	i = -1;
	s1ok = 0;
	s2ok = 0;
	while (++i < SIZE && (!s1ok || !s2ok))
	{
		if (TUBOARD[s1][i] == s2)
			s1ok++;
		if (TUBOARD[s1][i] == -2147483648 && !s1ok++)
			TUBOARD[s1][i] = s2;
		if (TUBOARD[s2][i] == s1)
			s2ok++;
		if (TUBOARD[s2][i] == -2147483648 && !s2ok++)
			TUBOARD[s2][i] = s1;
	}
	return (1);
}

int		check_name(t_data *data, char *line, int size)
{
	int		index;
	char	tmp;

	index = 0;
	tmp = line[size];
	line[size] = '\0';
	while (index < SIZE)
	{
		if (!ft_strcmp(ROOMS[index]->name, line))
		{
			line[size] = tmp;
			return (index);
		}
		index++;
	}
	return (-1);
}

int		check_tube(t_data *data, char *line)
{
	int i;
	int j;
	int s1;
	int s2;

	i = 0;
	if (!line[(i = skip_sp(line, 0))])
		return (0);
	j = i;
	while (line[j] && line[j] != '-')
		j++;
	if (!line[j] || (s1 = check_name(data, line + i, j - i)) == -1)
		return (0);
	i = j + 1;
	while (line[++j] && line[j] != ' ' && line[j] != '\t')
		;
	if ((s2 = check_name(data, line + i, j - i)) == -1)
		return (0);
	return (s1 == s2 ? 1 : add_tube(data, s1, s2));
}

int		init_get_tube(t_data *data, char *line)
{
	if (data->next_start != 2 || data->next_end != 2)
		return (ft_memdel((void **)&line, 0));
	if ((SIZE = room_nbr(data)) >= INTMAX / 2
		|| (!ROOMS && !make_rooms(SIZE, data)))
		return (ft_memdel((void **)&line, 0));
	if (!TUBOARD && !make_tuboard(SIZE, data))
		return (ft_memdel((void **)&line, 0));
	if (!check_tube(data, line))
		return (ft_memdel((void **)&line, 0));
	else if (!(strcat_lemin(data->input, line, &(data->len_input), data)))
		return (ft_memdel((void **)&line, 0));
	return (1);
}

int		get_tube(t_data *data, char *line)
{
	int		r;

	r = 0;
	if (!(r = init_get_tube(data, line)))
		return (free_data(data));
	while ((r = get_line(&line, data) > 0))
		if (*line != '#' && !check_tube(data, line))
			return (ft_memdel((void **)&line, -1));
		else if (!get_hash(line, data))
			return (ft_memdel((void **)&line, -1));
		else if (!(strcat_lemin(data->input, line, &(data->len_input), data)))
			return (ft_memdel((void **)&line, free_data(data)));
	if (r == -1)
		return (free_data(data));
	return (1);
}
