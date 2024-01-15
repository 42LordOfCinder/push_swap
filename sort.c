/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:56:34 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/03 18:48:03 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *s)
{
	int	max;
	int	min;

	if (s->size == 3 && !ft_is_sorted(s, ft_smaller))
	{
		max = ft_get_index(s, ft_greater);
		min = ft_get_index(s, ft_smaller);
		if ((max == 2 && min == 1) || (max == 1 && !min) || (!max && min == 2))
			ft_swap(s, 1);
		if ((!max && min == 1) || (max == 1 && !min))
			ft_rotate(s, 1);
		if ((max == 1 && min == 2) || (!max && min == 2))
			ft_reverse_rotate(s, 1);
	}
}

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->size >= 4 && !ft_is_sorted(a, ft_smaller))
	{
		ft_push(b, a, 1);
		if (a->size >= 4)
			ft_push(b, a, 1);
		ft_push_to_b_desc(a, b);
		ft_sort_3(a);
		ft_push_to_a_asc(a, b);
		ft_get_good_rotation_asc(a);
	}
}

void	ft_sort_main(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (ft_get_index(a, ft_greater) == 0)
			ft_swap(a, 1);
	}
	else if (a->size == 3)
		ft_sort_3(a);
	else if (a->size >= 4)
		ft_sort(a, b);
	free(a->array);
	free(b->array);
}
