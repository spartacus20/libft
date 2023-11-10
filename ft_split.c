/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:27:10 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/09 13:00:18 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_elements(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	return (count);
}

char	*allocate_memmory(char *arr, int count)
{
	arr = (char *)malloc(sizeof(char) * (count + 1));
	if (!arr)
		return (NULL);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;
	int		j;
	int		i;

	count = count_elements(s, c);
	i = 0;
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	while (i < count)
	{
		j = 0;
		while (s[j] != c && s[j] != '\0')
			j++;
		arr[i] = allocate_memmory(arr[i], j);
		ft_memcpy(arr[i], s, j);
		arr[i][j] = '\0';
		s += j;
		while (*s == c)
			s++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
