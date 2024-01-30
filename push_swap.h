/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:10:45 by gmassoni          #+#    #+#             */
/*   Updated: 2024/01/12 16:16:58 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// Stack structure
typedef struct s_stack
{
	int		*array;
	int		size;
	char	name;	
}	t_stack;

// Cost structure
typedef struct s_cost
{
	int	rs1;
	int	rrs1;
	int	rs2;
	int	rrs2;
}	t_cost;

// Main
int		main(int argc, char *argv[]);
int		ft_handle_parsing(int argc, char **argv, t_stack *a, t_stack *b);

// Parsing helpers
long	ft_atol(char *str);
int		ft_strslen(char *strs[]);
int		ft_check_duplicates(int *a, int len);
int		*ft_parse(char *strs[], int len);
int		ft_create_stacks(int len, int **parsed, t_stack *a, t_stack *b);
char	**ft_split(const char *s, char c);

// Operations
void	ft_swap(t_stack *s, int print_bool);
void	ft_ss(t_stack *a, t_stack *b, int print_bool);
void	ft_push(t_stack *s1, t_stack *s2, int print_bool);
void	ft_rotate(t_stack *s, int print_bool);
void	ft_rr(t_stack *a, t_stack *b, int print_bool);
void	ft_reverse_rotate(t_stack *s, int print_bool);
void	ft_rrr(t_stack *a, t_stack *b, int print_bool);

// Sorting
void	ft_sort_main(t_stack *a, t_stack *b);
void	ft_sort_3(t_stack *s);
void	ft_sort(t_stack *a, t_stack *b);

// Sorting helpers
int		ft_smaller(int i, int j);
int		ft_greater(int i, int j);
int		ft_is_sorted(t_stack *s, int f(int, int));
int		ft_get_index(t_stack *s, int f(int, int));
int		ft_get_relative(t_stack *s1, t_stack *s2, int ind, int f(int, int));
int		ft_calculate_double_rotates(t_cost *rcost);
int		ft_calculate_cost(t_stack *s1, t_stack *s2, int s1_ind, int s2_ind);
int		ft_get_index_to_push(t_stack *s1, t_stack *s2, int f(int, int));
void	ft_push_to_a_asc(t_stack *a, t_stack *b);
void	ft_push_to_b_desc(t_stack *a, t_stack *b);
void	ft_applicate_rotations(t_stack *a, t_stack *b, t_cost *rcost);
void	ft_applicate_double_rotations(t_stack *a, t_stack *b, t_cost *rcost);
void	ft_push_by_best_cost(t_stack *a, t_stack *b, int a_ind, int b_ind);
void	ft_get_good_rotation_asc(t_stack *a);
#endif
