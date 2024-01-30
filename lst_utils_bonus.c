/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:58:09 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/03 19:10:10 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_lst_new(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(content);
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return (NULL);
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
	return (*lst);
}

void	ft_lst_free(t_list **lst)
{
	if (!lst || !(*lst))
		return ;
	if ((*lst)->next)
		ft_lst_free((&(*lst)->next));
	free((*lst)->content);
	free(*lst);
	*lst = NULL;
}
