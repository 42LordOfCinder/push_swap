/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:08:47 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/03 18:56:23 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_applicate_double_rotations(t_stack *s1, t_stack *s2, t_cost *rcost)
{
	while (rcost->rs1 > 0 && rcost->rs2 > 0)
	{
		ft_rr(s1, s2, 1);
		rcost->rs1--;
		rcost->rs2--;
	}
	while (rcost->rrs1 > 0 && rcost->rrs2 > 0)
	{
		ft_rrr(s1, s2, 1);
		rcost->rrs1--;
		rcost->rrs2--;
	}
}

void	ft_applicate_rotations(t_stack *s1, t_stack *s2, t_cost *rcost)
{
	ft_applicate_double_rotations(s1, s2, rcost);
	while (rcost->rs1 > 0)
	{
		ft_rotate(s1, 1);
		rcost->rs1--;
	}
	while (rcost->rs2 > 0)
	{
		ft_rotate(s2, 1);
		rcost->rs2--;
	}
	while (rcost->rrs1 > 0)
	{
		ft_reverse_rotate(s1, 1);
		rcost->rrs1--;
	}
	while (rcost->rrs2 > 0)
	{
		ft_reverse_rotate(s2, 1);
		rcost->rrs2--;
	}
}

void	ft_push_by_best_cost(t_stack *s1, t_stack *s2, int s1_ind, int s2_ind)
{
	t_cost	rcost;

	rcost.rs1 = 0;
	rcost.rrs1 = 0;
	rcost.rs2 = 0;
	rcost.rrs2 = 0;
	if (((float) s1_ind) >= ((float) s1->size) / 2)
		rcost.rrs1 = s1->size - s1_ind;
	else
		rcost.rs1 = s1_ind;
	if (((float) s2_ind) >= ((float) s2->size) / 2)
		rcost.rrs2 = s2->size - s2_ind;
	else
		rcost.rs2 = s2_ind;
	ft_applicate_rotations(s1, s2, &rcost);
	ft_push(s2, s1, 1);
}

void	ft_get_good_rotation_asc(t_stack *a)
{
	int	min_index;

	min_index = ft_get_index(a, ft_smaller);
	if ((float) min_index >= ((float) a->size) / 2)
	{
		while (min_index != 0)
		{
			ft_reverse_rotate(a, 1);
			min_index = ft_get_index(a, ft_smaller);
		}
	}
	else
	{
		while (min_index != 0)
		{
			ft_rotate(a, 1);
			min_index = ft_get_index(a, ft_smaller);
		}
	}
}

void	ft_push_to_a_asc(t_stack *a, t_stack *b)
{
	int	relative_index;
	int	push_index;

	while (b->size > 0)
	{
		push_index = ft_get_index_to_push(b, a, ft_greater);
		relative_index = ft_get_relative(b, a, push_index, ft_greater);
		ft_push_by_best_cost(b, a, push_index, relative_index);
	}
}
