/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 06:46:42 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/03 18:47:38 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_msg(t_stack *s)
{
	write(1, "p", 1);
	write(1, &s->name, 1);
	write(1, "\n", 1);
}

// Put A first to do a PA and B first to do a PB
void	ft_push(t_stack *s1, t_stack *s2, int print_bool)
{
	int	i;
	int	tmp;

	if (s2->size >= 1)
	{
		tmp = s2->array[0];
		i = 0;
		while (i < s2->size - 1)
		{
			s2->array[i] = s2->array[i + 1];
			i++;
		}
		s2->size--;
		i = s1->size;
		while (i > 0)
		{
			s1->array[i] = s1->array[i - 1];
			i--;
		}
		s1->array[0] = tmp;
		s1->size++;
		if (print_bool)
			ft_print_msg(s1);
	}
}
