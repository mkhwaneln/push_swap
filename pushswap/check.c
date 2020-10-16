/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:47:55 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 10:53:31 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int		ft_issorted(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < (stack->stack_size - 1))
	{
		if (stack->numbers[i] < stack->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}
