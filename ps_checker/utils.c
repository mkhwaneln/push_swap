/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:40:21 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 12:20:51 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_isnumber(char *str)
{
	int		index;

	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-' && ft_isdigit(str[index + 1]) == 1)
		index++;
	while ((str[index] != '\0') && (ft_isdigit(str[index])))
	{
		if (str[index] == ' ' && (ft_isdigit(str[index - 1]) == 1 ||
					ft_isdigit(str[index + 1]) == 1))
			index++;
		else if (ft_isdigit(str[index]))
			index++;
	}
	if (str[index] == '\0')
		return (1);
	return (0);
}

void	push(t_stack *stack, long num)
{
	stack->top = stack->top + 1;
	stack->numbers[stack->top] = num;
	stack->stack_size++;
}

int		pop(t_stack *stack)
{
	if (!ft_isempty(stack->top))
	{
		stack->stack_size--;
		return (stack->numbers[stack->top--]);
	}
	return (0);
}

int		ft_issorted(t_stack *stack_a)
{
	int		i;

	i = 1;
	if (stack_a->stack_size == 1)
		return (1);
	while (i < stack_a->stack_size)
	{
		if (stack_a->numbers[i - 1] < stack_a->numbers[i])
			return (0);
		i++;
	}
	return (1);
}
