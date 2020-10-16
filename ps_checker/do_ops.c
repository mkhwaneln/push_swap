/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:30:03 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 10:34:20 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rev_rot_instruct(t_stacks *stacks, char *instruct)
{
	if (ft_strncmp(instruct, "rra", 3) == 0)
		rev_rot_stack(stacks->stack_a);
	else if (ft_strncmp(instruct, "rrb", 3) == 0)
		rev_rot_stack(stacks->stack_b);
	else if (ft_strncmp(instruct, "rrr", 3) == 0)
		reverse_rotate(stacks);
	else
		display_error(stacks);
}

void	rotate_instruct(t_stacks *stacks, char *instruct)
{
	if (ft_strncmp(instruct, "ra", 2) == 0)
		rotate_stack(stacks->stack_a);
	else if (ft_strncmp(instruct, "rb", 2) == 0)
		rotate_stack(stacks->stack_b);
	else if (ft_strncmp(instruct, "rr", 2) == 0)
		rotate(stacks);
	else
		display_error(stacks);
}

void	push_instruct(t_stacks *stacks, char *instruct)
{
	if (ft_strncmp(instruct, "pa", 2) == 0)
		push_a(stacks);
	else if (ft_strncmp(instruct, "pb", 2) == 0)
		push_b(stacks);
	else
		display_error(stacks);
}

void	swap_instruct(t_stacks *stacks, char *instruct)
{
	if (ft_strncmp(instruct, "sa", 2) == 0)
		swap_stack(stacks->stack_a);
	else if (ft_strncmp(instruct, "sb", 2) == 0)
		swap_stack(stacks->stack_b);
	else if (ft_strncmp(instruct, "ss", 2) == 0)
		swap_both(stacks);
	else
		display_error(stacks);
}

int		do_instruct(t_stacks *stacks, char *instruct)
{
	if (ft_strlen(instruct) == 2)
	{
		if ((ft_strncmp(instruct, "sa", 2) == 0) ||
				(ft_strncmp(instruct, "sb", 2) == 0) ||
				(ft_strncmp(instruct, "ss", 2) == 0))
			swap_instruct(stacks, instruct);
		else if ((ft_strncmp(instruct, "pa", 2) == 0) ||
				(ft_strncmp(instruct, "pb", 2) == 0))
			push_instruct(stacks, instruct);
		else if ((ft_strncmp(instruct, "ra", 2) == 0) ||
				(ft_strncmp(instruct, "rb", 2) == 0) ||
				(ft_strncmp(instruct, "rr", 2) == 0))
			rotate_instruct(stacks, instruct);
		else
			display_error(stacks);
	}
	else if (ft_strlen(instruct) == 3)
		rev_rot_instruct(stacks, instruct);
	else
		display_error(stacks);
	return (1);
}
