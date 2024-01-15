/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:00:46 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/12 17:56:47 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = (res * 10) + (str[i] - 48);
			i++;
		}
		else
			return (-2147483649);
	}
	if (str[i - 1] >= '0' && str[i - 1] <= '9')
		return (res * sign);
	return (-2147483649);
}

int	ft_strslen(char *strs[])
{
	int	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}

int	ft_check_duplicates(int *parsed, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (parsed[i] == parsed[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_parse(char *strs[], int len)
{
	int		*parsed;
	int		i;
	long	tmp;

	if (!len)
		return (NULL);
	i = 0;
	parsed = malloc(sizeof(int) * len);
	if (parsed == NULL)
		return (NULL);
	while (i < len)
	{
		tmp = ft_atol(strs[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			free(parsed);
			return (NULL);
		}
		parsed[i] = (int) tmp;
		i++;
	}
	if (!ft_check_duplicates(parsed, len))
		return (parsed);
	free(parsed);
	return (NULL);
}

int	ft_create_stacks(int len, int **parsed, t_stack *a, t_stack *b)
{
	a->size = len;
	a->name = 'a';
	a->array = *parsed;
	b->size = 0;
	b->name = 'b';
	b->array = malloc(sizeof(int) * len);
	if (b->array == NULL)
		return (0);
	return (1);
}
