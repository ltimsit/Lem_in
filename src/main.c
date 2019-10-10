/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:36:12 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/15 17:08:09 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int		init_data(t_data *data)
{
	data->nb_ant = 0;
	data->round = INTMAX;
	PMAX = 0;
	data->room = NULL;
	SIZE = 0;
	HEAD = NULL;
	data->tail = NULL;
	ROOMS = NULL;
	TUBOARD = NULL;
	DIS_TUBOARD = NULL;
	data->next_start = 0;
	data->next_end = 0;
	P2 = NULL;
	P1 = NULL;
	data->len_max = BUF_INPUT;
	if (!(data->input = ft_strnew(data->len_max)))
		return (0);
	data->len_input = 0;
	data->list_on = true;
	data->display = false;
	return (1);
}

int		print_error(int o)
{
	if (!o)
		write(2, "\033[31mERROR\033[0m\n", 15);
	else if (o == 1)
		write(2, "\033[31mFILE ERROR\033[0m\n", 20);
	return (0);
}

int		get_fd(char *av0, int ac, t_data *data, char **av)
{
	int		i;

	i = 0;
	data->fd = 0;
	while (ft_strcmp(av0 + i, "lem_in"))
		i++;
	data->path[i] = '\0';
	data->path_size = i;
	while (--i >= 0)
		data->path[i] = av0[i];
	if (ac > 2 && !ft_strcmp("--file", av[1]))
	{
		ft_strcat(data->path, av[2]);
		if ((data->fd = open(data->path, O_RDONLY)) < 0)
			return (print_error(1));
	}
	else if (ac > 1)
	{
		write(2, "usage : --file <filename>\n", 26);
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_data	data;
	char	*line;
	int		tube;

	line = NULL;
	if (!(get_fd(av[0], ac, &data, ac > 2 ? av : NULL)))
		return (0);
	if (!(init_data(&data)))
		return (0);
	tube = 0;
	if (!(get_nb_ant(&data, line)) || !(tube = get_room_info(&data, &line)))
		return (print_error(0));
	if (tube == -1 && !get_tube(&data, line))
		return (print_error(0));
	data.path_max = get_max_path_nb(&data);
	if (!create_path_1_and_2(&data))
		return (free_data(&data));
	if (data.display && data.size <= 42)
		make_display_tuboard(&data);
	path_finding(&data);
	if (data.display && data.size <= 42)
		init_display(&data);
	free_data(&data);
	return (0);
}
