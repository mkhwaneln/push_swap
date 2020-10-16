/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:54:35 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 10:55:20 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_stacks(t_stacks *stacks)
{
	free(stacks->stack_a->numbers);
	free(stacks->stack_b->numbers);
	exit(1);
}

void	display_error(t_stacks *stacks)
{
	ft_putendl("Error");
	free(stacks->stack_a->numbers);
	free(stacks->stack_b->numbers);
	exit(1);
}
