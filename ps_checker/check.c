/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:05:06 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 12:01:47 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_isduplicate(t_stack *stack, long number)
{
	int		index;

	index = 0;
	while (index <= stack->top)
	{
		if (stack->numbers[index] == number)
			return (1);
		index++;
	}
	return (0);
}

int		ft_isvalid(long number)
{
	if (number > MAX_INT || number < MIN_INT)
		return (0);
	else
		return (1);
}

int		ft_isempty(int top)
{
	if (top == -1)
		return (1);
	return (0);
}
