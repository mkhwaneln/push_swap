/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:37:48 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 13:05:55 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_stack(t_stack *stack)
{
	int		temp;

	if (stack->top >= 2)
	{
		temp = stack->numbers[stack->top];
		stack->numbers[stack->top] = stack->numbers[stack->top - 1];
		stack->numbers[stack->top - 1] = temp;
	}
}

void	swap_both(t_stacks *stacks)
{
	swap_stack(stacks->stack_a);
	swap_stack(stacks->stack_b);
	ft_putendl("ss");
}

void	push_a(t_stacks *stacks)
{
	int		temp;

	if (!ft_isempty(stacks->stack_b->top))
	{
		temp = pop(stacks->stack_b);
		push(stacks->stack_a, temp);
	}
	ft_putendl("pa");
}

void	push_b(t_stacks *stacks)
{
	int		temp;

	if (!ft_isempty(stacks->stack_a->top))
	{
		temp = pop(stacks->stack_a);
		push(stacks->stack_b, temp);
	}
	ft_putendl("pb");
}
