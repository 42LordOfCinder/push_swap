/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:09:31 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/03 18:46:08 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *s, int print_bool)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = s->array[0];
	while (i < s->size - 1)
	{
		s->array[i] = s->array[i + 1];
		i++;
	}
	s->array[s->size - 1] = tmp;
	if (print_bool)
	{
		write(1, "r", 1);
		write(1, &s->name, 1);
		write(1, "\n", 1);
	}
}

void	ft_rr(t_stack *a, t_stack *b, int print_bool)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	if (print_bool)
		write(1, "rr\n", 3);
}

void	ft_reverse_rotate(t_stack *s, int print_bool)
{
	int		tmp;
	int		i;

	i = s->size - 1;
	tmp = s->array[i];
	while (i > 0)
	{
		s->array[i] = s->array[i - 1];
		i--;
	}
	s->array[0] = tmp;
	if (print_bool)
	{
		write(1, "rr", 2);
		write(1, &s->name, 1);
		write(1, "\n", 1);
	}
}

void	ft_rrr(t_stack *a, t_stack *b, int print_bool)
{
	ft_reverse_rotate(a, 0);
	ft_reverse_rotate(b, 0);
	if (print_bool)
		write(1, "rrr\n", 4);
}
