/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:41:59 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/13 15:17:44 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <stdlib.h>

int		get_line(char **line, t_data *data)
{
	int		ret;

	ret = 0;
	ft_memdel((void**)line, 1);
	return ((ret = ft_get_next_line(data->fd, line, 0)));
}

int		get_nb_ant(t_data *data, char *line)
{
	int		r;

	r = 0;
	while (!data->nb_ant && (r = get_line(&line, data)))
		if (r == -1 || (line && line[0] == '#' && !get_hash(line, data)))
			return (ft_memdel((void **)&line, free_data(data)));
		else if (line[0] != '#' && (data->nb_ant = ft_atoi(line)) < 1)
			return (ft_memdel((void **)&line, free_data(data)));
		else if (!r || !(strcat_lemin(data->input, line,
						&(data->len_input), data)))
			return (free_data(data));
	return (ft_memdel((void **)&line, 1));
}

int		get_hash(char *line, t_data *data)
{
	if (data->next_start == 1 || data->next_end == 1)
		return (0);
	if (line[1] != '#')
		return (1);
	else if (!ft_strcmp(line + 2, "display"))
		data->display = true;
	else if (!ft_strcmp(line + 2, "start"))
		(data->next_start)++;
	else if (!ft_strcmp(line + 2, "end"))
		(data->next_end)++;
	if (data->next_start > 2 || data->next_end > 2)
		return (0);
	return (1);
}

int		check_room(t_data *data, char *line)
{
	int		i;
	int		j;
	int		k;

	if (!line[(i = skip_sp(line, 0))] || line[i] == 'L' || line[i] == '#')
		return (0);
	if ((j = skip_nosp(line, i)) == -1)
		return (-1);
	if (j - i == 0 || !(data->room = list_room_new(line + i, j - i, data)))
		return (0);
	k = i + j;
	if ((k = skip_nodigit(line, k)) && !line[k])
		return (0);
	data->room->x = ft_atoi(line + k);
	if ((k = skip_digit(line, k))
		&& (k = skip_nodigit(line, k)) && !line[k])
		return (0);
	data->room->y = ft_atoi(line + k);
	if (!check_bad_info(data))
		return (0);
	return (1);
}

int		get_room_info(t_data *data, char **line)
{
	int		r;
	int		tube;

	r = 0;
	tube = 0;
	while (tube != -1 && (r = get_line(line, data) > 0))
	{
		if (**line != '#' && !(tube = check_room(data, *line)))
			return (ft_memdel((void **)line, free_data(data)));
		else if (tube != -1 && !get_hash(*line, data))
			return (ft_memdel((void **)line, free_data(data)));
		if (tube != -1 && !(strcat_lemin(data->input, *line,
						&(data->len_input), data)))
			return (ft_memdel((void **)line, free_data(data)));
	}
	return (tube == -1 ? -1 : 0);
}
