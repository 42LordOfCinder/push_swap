/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 06:35:22 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/03 18:46:36 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *s, int print_bool)
{
	int		tmp;

	if (s->size >= 2)
	{
		tmp = s->array[0];
		s->array[0] = s->array[1];
		s->array[1] = tmp;
		if (print_bool)
		{
			write(1, "s", 1);
			write(1, &s->name, 1);
			write(1, "\n", 1);
		}
	}
}

void	ft_ss(t_stack *a, t_stack *b, int print_bool)
{
	ft_swap(a, 0);
	ft_swap(b, 0);
	if (print_bool)
		write(1, "ss\n", 3);
}
