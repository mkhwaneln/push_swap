/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:00:41 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 13:36:17 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../../libft/libft.h"

# define MAX_INT	2147483647
# define MIN_INT	-2147483648

typedef struct		s_stack
{
	long			*numbers;
	int				stack_size;
	int				top;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_stacks;

void				swap_stack(t_stack *stack);
void				swap_both(t_stacks *stacks);
void				push_a(t_stacks *stacks);
void				push_b(t_stacks *stacks);
void				rotate_stack(t_stack *stack);
void				rotate(t_stacks *stacks);
void				rev_rot_stack(t_stack *stack);
void				reverse_rotate(t_stacks *stacks);
void				push_to_stack(t_stacks *stacks, int count, char **input);
void				push(t_stack *stack, long num);
int					pop(t_stack *stack);
int					find_max(t_stack *stack);
int					find_min(t_stack *stack);
int					ft_isnumber(char *str);
int					ft_isvalid(long number);
int					ft_isduplicate(t_stack *stack, long number);
int					ft_isempty(int top);
int					ft_issorted(t_stack *stack);
void				init_push_swap(t_stacks *stacks, int argc, char **argv);
void				push_swap_2(t_stacks *stacks);
void				push_swap_3(t_stacks *stacks);
void				push_swap(t_stacks *stacks);
void				free_stacks(t_stacks *stacks);
void				display_error(t_stacks *stacks);

#endif
