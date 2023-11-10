/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:33:05 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/08 16:07:08 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!rptr)
		return (NULL);
	while (s1[j] != '\0')
	{
		if (strchr(set, s1[j]) != NULL)
		{
			j++;
		}
		else
		{
			rptr[i] = s1[j];
			i++;
			j++;
		}
	}
	rptr[i] = '\0';
	return (rptr);
}
