/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:02:21 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 13:00:37 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		store_numbers(t_stacks *stacks, char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while (*str)
	{
		if (*str == '-')
			sign = -1;
		else if (ft_isdigit(*str))
			number = (number * 10) + (*str - '0');
		if (!(*(str + 1)))
		{
			number = number * sign;
			if (!(ft_isvalid(number)) ||
					(ft_isduplicate(stacks->stack_a, number)))
				display_error(stacks);
			push(stacks->stack_a, number);
			number = 0;
			sign = 1;
		}
		str++;
	}
}

void			push_to_stack(t_stacks *stacks, int count, char **input)
{
	int		i;

	i = count - 1;
	while (i > 0)
	{
		store_numbers(stacks, input[i]);
		i--;
	}
}

static void		init_stack(t_stacks *stacks, int size, char **input)
{
	int		count;

	count = 1;
	while (count < size)
	{
		if (ft_isnumber(input[count]) != 1)
		{
			ft_putendl("Error");
			exit(1);
		}
		count++;
	}
	stacks->stack_a->numbers = (long *)malloc(sizeof(long) * (size - 1));
	stacks->stack_a->stack_size = 0;
	stacks->stack_a->top = -1;
	stacks->stack_b->numbers = (long *)malloc(sizeof(long) * (size - 1));
	stacks->stack_b->stack_size = 0;
	stacks->stack_b->top = -1;
}

int				main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 2)
	{
		ft_putendl("");
		return (0);
	}
	else if (argc > 2)
	{
		stacks.stack_a = (t_stack *)malloc(sizeof(t_stack));
		stacks.stack_b = (t_stack *)malloc(sizeof(t_stack));
		init_stack(&stacks, argc, argv);
		init_push_swap(&stacks, argc, argv);
	}
	else if (argc == 1)
	{
		ft_putendl("usage: ./push_swap [param1] [param2] ... ");
		return (0);
	}
	free(stacks.stack_a);
	free(stacks.stack_b);
	return (0);
}
