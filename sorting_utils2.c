/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:52:43 by gmassoni          #+#    #+#             */
/*   Updated: 2023/12/26 15:02:08 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_relative(t_stack *s1, t_stack *s2, int ind, int f(int, int))
{
	int	value;
	int	i;
	int	relative_index;

	value = s1->array[ind];
	relative_index = 0;
	i = 1;
	while (i < s2->size)
	{
		if (!f(s2->array[relative_index], value))
		{
			if (!f(s2->array[i], s2->array[relative_index]))
				relative_index = i;
			else if (f(s2->array[i], value))
				relative_index = i;
		}
		else
			if (f(s2->array[i], value))
				if (!f(s2->array[i], s2->array[relative_index]))
					relative_index = i;
		i++;
	}
	return (relative_index);
}

int	ft_calculate_double_rotates(t_cost *rcost)
{
	if (rcost->rs1 > 0 && rcost->rs2 > 0)
	{
		if (rcost->rs1 > rcost->rs2)
			return (rcost->rs1);
		else
			return (rcost->rs2);
	}
	else if (rcost->rrs1 > 0 && rcost->rrs2 > 0)
	{
		if (rcost->rrs1 > rcost->rrs2)
			return (rcost->rrs1);
		else
			return (rcost->rrs2);
	}
	return (rcost->rs1 + rcost->rrs1 + rcost->rs2 + rcost->rrs2);
}

int	ft_calculate_cost(t_stack *s1, t_stack *s2, int s1_ind, int s2_ind)
{
	int		cost;
	t_cost	rcost;

	cost = 0;
	rcost.rs1 = 0;
	rcost.rrs1 = 0;
	rcost.rrs2 = 0;
	rcost.rs2 = 0;
	if (((float) s1_ind) >= ((float) s1->size) / 2)
		rcost.rrs1 = s1->size - s1_ind;
	else
		rcost.rs1 = s1_ind;
	if (((float) s2_ind) >= ((float) s2->size) / 2)
		rcost.rrs2 = s2->size - s2_ind;
	else
		rcost.rs2 = s2_ind;
	cost = ft_calculate_double_rotates(&rcost);
	return (cost + 1);
}

int	ft_get_index_to_push(t_stack *s1, t_stack *s2, int f(int, int))
{
	int	cost;
	int	b_cost;
	int	i;
	int	index_to_push;

	index_to_push = 0;
	b_cost = ft_calculate_cost(s1, s2, 0, ft_get_relative(s1, s2, 0, f));
	if (b_cost == 1)
		return (index_to_push);
	i = 1;
	while (i < s1->size)
	{
		cost = ft_calculate_cost(s1, s2, i, ft_get_relative(s1, s2, i, f));
		if (cost < b_cost)
		{
			b_cost = cost;
			index_to_push = i;
		}
		i++;
	}
	return (index_to_push);
}

void	ft_push_to_b_desc(t_stack *a, t_stack *b)
{
	int	relative_index;
	int	push_index;

	while (a->size > 3 && !ft_is_sorted(a, ft_smaller))
	{
		push_index = ft_get_index_to_push(a, b, ft_smaller);
		relative_index = ft_get_relative(a, b, push_index, ft_smaller);
		ft_push_by_best_cost(a, b, push_index, relative_index);
	}
}
