/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 09:53:09 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 10:54:22 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

int					do_instruct(t_stacks *stacks, char *instruct);
void				swap_instruct(t_stacks *stacks, char *instruct);
void				push_instruct(t_stacks *stacks, char *instruct);
void				rotate_instruct(t_stacks *stacks, char *instruct);
void				rev_rot_instruct(t_stacks *stacks, char *instruct);
void				swap_stack(t_stack *stack);
void				swap_both(t_stacks *stacks);
void				push_a(t_stacks *stacks);
void				push_b(t_stacks *stacks);
void				rotate_stack(t_stack *stack);
void				rotate(t_stacks *stacks);
void				rev_rot_stack(t_stack *stack);
void				reverse_rotate(t_stacks *stacks);
int					ft_isnumber(char *str);
void				push(t_stack *stack, long num);
int					pop(t_stack *stack);
int					ft_isvalid(long number);
int					ft_isduplicate(t_stack *stack, long number);
int					ft_isempty(int top);
int					ft_issorted(t_stack *stack_a);
void				free_stacks(t_stacks *stacks);
void				display_error(t_stacks *stacks);

#endif
