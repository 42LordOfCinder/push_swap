/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:58:10 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/03 18:56:29 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Can be used for ASC && MIN && SMALLEST
int	ft_smaller(int i, int j)
{
	if (i < j)
		return (1);
	return (0);
}

// Can be used for DESC && MAX && GREATEST
int	ft_greater(int i, int j)
{
	if (i > j)
		return (1);
	return (0);
}

int	ft_is_sorted(t_stack *s, int f(int, int))
{
	int	i;

	i = 0;
	while (i < s->size - 1)
	{
		if (!f(s->array[i], s->array[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_index(t_stack *s, int f(int, int))
{
	int	i;
	int	searched;
	int	searched_index;

	i = 0;
	searched_index = 0;
	searched = s->array[0];
	while (i < s->size)
	{
		if (f(s->array[i], searched))
		{
			searched = s->array[i];
			searched_index = i;
		}
		i++;
	}
	return (searched_index);
}
