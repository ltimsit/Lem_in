/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:45:00 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/08/15 17:09:21 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char		*resize_input(t_data *data, int *index)
{
	char	*new;
	int		i;

	i = 0;
	data->len_max += BUF_INPUT;
	if (!(new = (char *)malloc(sizeof(char) * data->len_max + 1)))
		return (NULL);
	while (i < *index)
	{
		new[i] = data->input[i];
		i++;
	}
	ft_memdel((void**)&(data->input), 0);
	data->input = new;
	return (new);
}

char		*strcat_lemin(char *s1, char *s2, int *index, t_data *data)
{
	int i;

	i = 0;
	while (s2[i])
	{
		if (!data && *index == BUF_WRITE)
		{
			write(1, s1, *index);
			*index = 0;
		}
		if (data && *index == data->len_max)
			if (!(s1 = resize_input(data, index)))
				return (NULL);
		s1[(*index)++] = s2[i++];
	}
	if (data)
	{
		if (*index == data->len_max)
			if (!(s1 = resize_input(data, index)))
				return (NULL);
		s1[(*index)++] = '\n';
	}
	s1[*index] = '\0';
	return (s1);
}

void		itobuf(int n, char *str, int *ibuf)
{
	int copy;
	int	size;

	size = 1;
	copy = n;
	while (copy > 9)
	{
		copy /= 10;
		size++;
	}
	if (*ibuf + size >= BUF_WRITE)
	{
		write(1, str, *ibuf);
		*ibuf = 0;
	}
	copy = size;
	while (size--)
	{
		str[*ibuf + size] = n % 10 + '0';
		n /= 10;
	}
	*ibuf += copy;
}
