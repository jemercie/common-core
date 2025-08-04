/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemercie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:13:11 by jemercie          #+#    #+#             */
/*   Updated: 2023/02/20 14:52:14 by jemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}				t_stack;

// ------ push_swap.c
void	print_error(void);
void	index_list(int argc, t_stack **stack);
int		tablen(char **tab);
void	free_tab(char **tab);
int		get_the_quotes(t_stack **stack_a, char *argv, int argc);

// ------ check.c
int		check_format(char *argv);
int		is_int(char *argv, int start, char *set);
int		check_int(char *argv, int start, int end);
int		check_double(t_stack *stack_a, int nb);
int		is_sorted(t_stack *stack_a);

// ------ manage_args.c
int		which_alg(int argc, t_stack **stack_a, t_stack **stack_b);
t_stack	*manage_args(int argc, char **argv, int i);
t_stack	*get_the_a_stack(int argc, char **argv, int min);
t_stack	*new_elmt(int content);
void	free_list(t_stack **stack_a);

// ------ swap.c
void	swap(t_stack **stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	swapswap(t_stack **stack_a, t_stack **stack_b);
int		is_swap(t_stack *stack, int reverse);

// ------ push.c
void	push(t_stack **stack_src, t_stack **stack_dest);
void	pa(t_stack **stack_src, t_stack **stack_dest);
void	pb(t_stack **stack_src, t_stack **stack_dest);

// ------ rotate.c
void	rotate(t_stack **stack);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rotarota(t_stack **stack_a, t_stack **stack_b);

// ------ reverse_rotate.c
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// ------ sort_one_to_five.c
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack);
void	sort_reverse_three(t_stack **stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

// ------ push_swap_utils.c
int		biggest_nb(t_stack	*stack);
int		smallest_nb(t_stack *stack);
int		is_sorted(t_stack *stack_a);
int		is_reverse_sorted(t_stack *stack);
int		is_index_sorted(t_stack *stack);

// ------ utils_a_to_b.c
int		is_ra_worth(int done, t_stack *stack);
int		is_rra_worth(int done, t_stack *stack);
void	ra_or_rra(int done, t_stack **stack_a);

// ------ utils_b_to_a.c
int		is_rb_worth(int target, t_stack *stack);
int		is_rrb_worth(int target, t_stack *stack);
void	rb_or_rrb(int done, t_stack **stack);

// ------ sort_the_rest.c
int		define_chunk(int done, int argc);
void	sort_the_rest(int argc, t_stack **stack_a, t_stack **stack_b);
void	a_to_b(int done, int chunk, t_stack **stack_a, t_stack **stack_b);
void	b_to_a(int done, t_stack **stack_a, t_stack **stack_b);
int		what_is_done(t_stack **stack_a, int done, int *i, int *j);

#endif
