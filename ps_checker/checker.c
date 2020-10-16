/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:16:20 by lmkhwane          #+#    #+#             */
/*   Updated: 2018/04/08 13:49:04 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		store_numbers(t_stacks *stacks, char *str)
{
	long		number;
	int			sign;

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

static int		push_to_stack(t_stacks *stacks, int count, char **input)
{
	int		i;

	i = count - 1;
	while (i > 0)
	{
		store_numbers(stacks, input[i]);
		i--;
	}
	return (1);
}

static void		init_stack(t_stacks *stacks, int size, char **input)
{
	int		count;

	count = 1;
	while (count < size)
	{
		if (ft_isnumber(input[count]) == 0)
		{
			ft_putendl("Error");
			exit(1);
		}
		count++;
	}
	stacks->stack_a->numbers = (long *)malloc(sizeof(long) * size);
	stacks->stack_a->stack_size = 0;
	stacks->stack_a->top = -1;
	stacks->stack_b->numbers = (long *)malloc(sizeof(long) * size);
	stacks->stack_b->stack_size = 0;
	stacks->stack_b->top = -1;
}

static void		get_instructions(t_stacks *stacks)
{
	char	*line;

	line = (char *)ft_memalloc(sizeof(char));
	while (read(0, line, 4) > 0)
	{
		if (!do_instruct(stacks, ft_strtrim(line)))
			display_error(stacks);
	}
	free(line);
}

int				main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc > 1)
	{
		stacks.stack_a = (t_stack *)malloc(sizeof(t_stack));
		stacks.stack_b = (t_stack *)malloc(sizeof(t_stack));
		init_stack(&stacks, argc, argv);
		if (push_to_stack(&stacks, argc, argv))
			get_instructions(&stacks);
		if (ft_issorted(stacks.stack_a) == 1 && stacks.stack_b->top == -1)
			ft_putendl("OK");
		else
			ft_putendl("KO");
	}
	else if (argc == 1)
	{
		ft_putendl("usage: ./checker [param1] [param2] ... ");
		return (0);
	}
	free(stacks.stack_a);
	free(stacks.stack_b);
	return (0);
}
