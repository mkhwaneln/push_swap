/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:34:31 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 10:35:15 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
