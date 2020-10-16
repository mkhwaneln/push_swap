/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:35:25 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 13:07:36 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_stack(t_stack *stack)
{
	int		temp;
	int		in;

	temp = stack->numbers[stack->top];
	in = stack->top;
	while (in > 0)
	{
		stack->numbers[in] = stack->numbers[in - 1];
		in--;
	}
	stack->numbers[0] = temp;
}

void	rotate(t_stacks *stacks)
{
	rotate_stack(stacks->stack_a);
	rotate_stack(stacks->stack_b);
	ft_putendl("rr");
}

void	rev_rot_stack(t_stack *stack)
{
	int		temp;
	int		in;

	temp = stack->numbers[0];
	in = 0;
	while (in < stack->top)
	{
		stack->numbers[in] = stack->numbers[in + 1];
		in++;
	}
	stack->numbers[stack->top] = temp;
}

void	reverse_rotate(t_stacks *stacks)
{
	rev_rot_stack(stacks->stack_a);
	rev_rot_stack(stacks->stack_b);
	ft_putendl("rrr");
}
