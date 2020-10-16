/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 12:25:46 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 13:33:44 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_swap_2(t_stacks *stacks)
{
	if (ft_issorted(stacks->stack_a))
	{
		ft_putendl("");
		free_stacks(stacks);
	}
	else
	{
		swap_stack(stacks->stack_a);
		ft_putendl("sa");
	}
}

void	init_push_swap(t_stacks *stacks, int argc, char **argv)
{
	push_to_stack(stacks, argc, argv);
	if (stacks->stack_a->stack_size == 2)
		push_swap_2(stacks);
	if (stacks->stack_a->stack_size == 3)
		push_swap_3(stacks);
	if (stacks->stack_a->stack_size > 3)
		push_swap(stacks);
}
