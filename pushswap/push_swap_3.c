/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:23:32 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 13:32:54 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		swap_stack_3(t_stack *stack)
{
	if (!ft_issorted(stack))
	{
		swap_stack(stack);
		ft_putendl("sa");
	}
}

static void		do_push_swap_3(t_stack *stack)
{
	int		max;

	if ((max = find_max(stack)) == 0)
	{
		swap_stack(stack);
		ft_putendl("sa");
	}
	else if ((max = find_max(stack)) == 1)
	{
		rev_rot_stack(stack);
		ft_putendl("rra");
		swap_stack_3(stack);
	}
	else
	{
		rotate_stack(stack);
		ft_putendl("ra");
		swap_stack_3(stack);
	}
}

void			push_swap_3(t_stacks *stacks)
{
	if (!ft_issorted(stacks->stack_a))
		do_push_swap_3(stacks->stack_a);
	else
	{
		ft_putendl("");
		free_stacks(stacks);
	}
}
