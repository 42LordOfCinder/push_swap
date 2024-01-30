/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:37:47 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/12 16:47:35 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_instructions(t_stack *a, t_stack *b)
{
	t_list	*inst;

	inst = ft_parse_instructions();
	if (!inst || !ft_verify_instructions(a, b, inst))
	{
		free(a->array);
		free(b->array);
		write(2, "Error\n", 6);
		return ;
	}
	if (ft_is_sorted(a, ft_smaller) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a->array);
	free(b->array);
	ft_lst_free(&inst);
}

int	ft_apply_instructions(t_stack *a, t_stack *b, t_list *inst)
{
	if (ft_str_eq(inst->content, "pa\n"))
		ft_push(a, b, 0);
	else if (ft_str_eq(inst->content, "pb\n"))
		ft_push(b, a, 0);
	else if (ft_str_eq(inst->content, "sa\n"))
		ft_swap(a, 0);
	else if (ft_str_eq(inst->content, "sb\n"))
		ft_swap(b, 0);
	else if (ft_str_eq(inst->content, "ss\n"))
		ft_ss(a, b, 0);
	else if (ft_str_eq(inst->content, "ra\n"))
		ft_rotate(a, 0);
	else if (ft_str_eq(inst->content, "rb\n"))
		ft_rotate(b, 0);
	else if (ft_str_eq(inst->content, "rr\n"))
		ft_rr(a, b, 0);
	else if (ft_str_eq(inst->content, "rra\n"))
		ft_reverse_rotate(a, 0);
	else if (ft_str_eq(inst->content, "rrb\n"))
		ft_reverse_rotate(b, 0);
	else if (ft_str_eq(inst->content, "rrr\n"))
		ft_rrr(a, b, 0);
	else
		return (0);
	return (1);
}

int	ft_str_eq(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

int	ft_verify_instructions(t_stack *a, t_stack *b, t_list *inst)
{
	t_list	*inst_cpy;

	inst_cpy = inst;
	while (inst && inst->content)
	{
		if (!ft_apply_instructions(a, b, inst))
		{
			ft_lst_free(&inst_cpy);
			return (0);
		}
		inst = inst->next;
	}
	return (1);
}

t_list	*ft_parse_instructions(void)
{
	char	*str;
	t_list	*inst;
	t_list	*inst_cpy;

	str = get_next_line(0);
	if (!str)
		return (ft_lst_new(str));
	inst = ft_lst_new(str);
	if (!inst)
		return (NULL);
	inst_cpy = inst;
	str = get_next_line(0);
	while (str)
	{
		if (!ft_lstadd_back(&inst, ft_lst_new(str)))
		{
			ft_lst_free(&inst_cpy);
			return (NULL);
		}
		inst = inst->next;
		str = get_next_line(0);
	}
	return (inst_cpy);
}
