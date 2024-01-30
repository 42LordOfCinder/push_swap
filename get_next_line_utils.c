/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:04:11 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/02 21:16:24 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;

	if (!nmemb || !size)
		return (malloc(0));
	if ((nmemb * size / size) != nmemb)
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);
	while (size--)
		result[size] = 0;
	return (result);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i++] = src[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	len;
	char			*result;

	if (s1 == NULL)
		s1 = ft_calloc(sizeof(char), 1);
	if (s2 == NULL)
		s2 = ft_calloc(sizeof(char), 1);
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = ft_calloc(len + 1, 1);
	if (result == NULL)
		return (NULL);
	*result = 0;
	ft_strcat(result, (char *)s1);
	ft_strcat(result, (char *)s2);
	free(s1);
	s1 = NULL;
	return (result);
}
