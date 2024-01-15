/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:03:10 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/02 21:15:52 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_get_line_in_buffer(char *str, char *mem)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		i++;
		j = 0;
		while (str[i])
		{
			mem[j] = str[i];
			i++;
			j++;
		}
		mem[j] = 0;
		str[i - j] = 0;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t		value;
	static char	*mem[1024];
	char		*str;

	str = ft_calloc(1, 1);
	if (!mem[fd])
		mem[fd] = ft_calloc(BUFFER_SIZE + 1, 1);
	while (mem[fd] && str)
	{
		str = ft_strjoin(str, mem[fd]);
		if (ft_get_line_in_buffer(str, mem[fd]))
			return (str);
		value = read(fd, mem[fd], BUFFER_SIZE);
		if (value <= 0)
		{
			free(mem[fd]);
			mem[fd] = NULL;
			if (str[0] != 0)
				return (str);
			free(str);
			return (NULL);
		}
		mem[fd][value] = 0;
	}
	return (NULL);
}
