/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 05:26:02 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/12 17:56:06 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

int	ft_handle_parsing(int argc, char *argv[], t_stack *a, t_stack *b)
{
	int		*parsed;
	int		len;
	char	**splitted;

	if (argc == 2)
	{
		splitted = ft_split(argv[1], ' ');
		if (!splitted)
			return (-1);
		len = ft_strslen(splitted);
		parsed = ft_parse(splitted, len);
		ft_free_splitted(splitted);
	}
	else
	{
		len = ft_strslen(argv + 1);
		parsed = ft_parse(argv + 1, len);
	}
	if (!parsed || !ft_create_stacks(len, &parsed, a, b))
	{
		if (parsed)
			free(a->array);
		return (-1);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		res;

	if (argc < 2)
		return (0);
	res = ft_handle_parsing(argc, argv, &a, &b);
	if (res == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	ft_sort_main(&a, &b);
	return (0);
}
