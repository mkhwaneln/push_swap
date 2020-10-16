/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkhwane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 15:34:13 by lmkhwane          #+#    #+#             */
/*   Updated: 2017/07/24 12:45:41 by lmkhwane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_len_c_stop(const char *str, int start, char c)
{
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[start] && (str[start] != c))
	{
		start++;
		counter++;
	}
	return (counter);
}

static int			ft_split_count(char const *s, char c)
{
	int		flag;
	int		words;
	int		count;
	char	*str;

	str = (char *)s;
	count = 0;
	words = 0;
	while (str[count] != '\0')
	{
		flag = 0;
		while ((str[count] != c) && str[count + 1])
		{
			if (flag == 0)
			{
				flag = 1;
				words++;
			}
			count++;
		}
		count++;
	}
	return (words);
}

char				**ft_strsplit(char const *s, char c)
{
	int		index;
	int		count1;
	int		word_c;
	char	**arr;
	char	*str;

	index = 0;
	count1 = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	word_c = ft_split_count(s, c);
	if (!(arr = (char **)ft_memalloc(sizeof(char *) * word_c + 1)))
		return (NULL);
	while (index < word_c)
	{
		while ((str[count1] == c) && str[count1])
			count1++;
		arr[index] = ft_strsub(str, count1, ft_len_c_stop(str, count1, c));
		while ((str[count1] != c) && str[count1])
			count1++;
		index++;
	}
	arr[index] = 0;
	return (arr);
}
