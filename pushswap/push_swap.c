/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:24:12 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 13:36:45 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		push_back_to_a(t_stacks *stacks)
{
	while (!ft_isempty(stacks->stack_b->top))
	{
		push_a(stacks);
		ft_putendl("pa");
	}
}

static void		ps_greater_than(t_stacks *stacks, int min_index)
{
	while (min_index != stacks->stack_a->stack_size - 1)
	{
		rotate_stack(stacks->stack_a);
		ft_putendl("ra");
		min_index++;
	}
	push_b(stacks);
	ft_putendl("pb");
}

static void		ps_less_than(t_stacks *stacks, int min_index)
{
	while (min_index > -1)
	{
		rev_rot_stack(stacks->stack_a);
		ft_putendl("rra");
		min_index--;
	}
	min_index = stacks->stack_a->stack_size - 1;
	push_b(stacks);
	ft_putendl("pb");
}

void			push_swap(t_stacks *stacks)
{
	int		min_index;

	if (ft_issorted(stacks->stack_a) == 0)
	{
		while (stacks->stack_a->stack_size > 3)
		{
			min_index = find_min(stacks->stack_a);
			if (min_index >= (stacks->stack_a->stack_size / 2))
				ps_greater_than(stacks, min_index);
			else if (min_index < (stacks->stack_a->stack_size / 2))
				ps_less_than(stacks, min_index);
		}
		if (!ft_issorted(stacks->stack_a))
			push_swap_3(stacks);
		push_back_to_a(stacks);
	}
	else
	{
		ft_putendl("");
		free_stacks(stacks);
	}
}
