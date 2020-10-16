/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 12:30:38 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 12:40:44 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		push(t_stack *stack, long num)
{
	stack->top = stack->top + 1;
	stack->numbers[stack->top] = num;
	stack->stack_size++;
}

int			pop(t_stack *stack)
{
	if (!ft_isempty(stack->top))
	{
		stack->stack_size--;
		return (stack->numbers[stack->top--]);
	}
	else
	{
		ft_putendl("Error");
		exit(1);
	}
}

int			find_max(t_stack *stack)
{
	int		max_index;
	int		temp;

	max_index = 0;
	temp = 0;
	if (stack->numbers[0] > stack->numbers[1])
	{
		temp = stack->numbers[0];
		max_index = 0;
	}
	else if (stack->numbers[0] < stack->numbers[1])
	{
		temp = stack->numbers[1];
		max_index = 1;
	}
	if (temp < stack->numbers[2])
		max_index = 2;
	return (max_index);
}

static int	find_min_in_stack(t_stack *stack, int index, int min_index,
		int temp)
{
	while (index < (stack->stack_size - 1))
	{
		if (temp > stack->numbers[index + 1])
		{
			temp = stack->numbers[index + 1];
			min_index = index + 1;
		}
		index++;
	}
	return (min_index);
}

int			find_min(t_stack *stack)
{
	int		min_index;
	int		index;
	int		temp;

	min_index = 0;
	index = 0;
	temp = 0;
	if (stack->numbers[index] < stack->numbers[index + 1])
	{
		temp = stack->numbers[index];
		min_index = index;
		index++;
	}
	else
	{
		temp = stack->numbers[index + 1];
		min_index = index;
		index++;
	}
	min_index = min_index + find_min_in_stack(stack, index, min_index,
			temp);
	return (min_index);
}
