/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:43:52 by abinois           #+#    #+#             */
/*   Updated: 2019/08/15 17:22:40 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		skip_sp(char *line, int i)
{
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

int		skip_nosp(char *line, int i)
{
	while (line[i] && line[i] != ' ' && line[i] != '\t')
	{
		if (line[i] == '-')
			return (-1);
		i++;
	}
	return (i);
}

int		skip_digit(char *line, int i)
{
	if (line[i] == '-')
		i++;
	while (line[i] && (ft_isdigit(line[i])))
		i++;
	return (i);
}

int		skip_nodigit(char *line, int i)
{
	while (line[i] && !ft_isdigit(line[i]) && !(line[i] == '-'
				&& ft_isdigit(line[i + 1])))
		i++;
	return (i);
}

int		check_bad_info(t_data *data)
{
	t_room	*tmp;

	tmp = HEAD;
	while (tmp->next)
	{
		if (tmp->x == data->room->x && tmp->y == data->room->y)
			return (0);
		if (!ft_strcmp(tmp->name, data->room->name))
			return (0);
		else
			tmp = tmp->next;
	}
	return (1);
}
