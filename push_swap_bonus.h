/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:24:27 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/03 19:12:29 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

// aint no way im writing that again
# include "push_swap.h"
# include "get_next_line.h"

// List
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

// List helpers
t_list	*ft_lst_new(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lst_free(t_list **lst);

// Helpers
void	ft_check_instructions(t_stack *a, t_stack *b);
int		ft_apply_instructions(t_stack *a, t_stack *b, t_list *inst);
int		ft_str_eq(char *s1, char *s2);
int		ft_verify_instructions(t_stack *a, t_stack *b, t_list *inst);
t_list	*ft_parse_instructions(void);
#endif
