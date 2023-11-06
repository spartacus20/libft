/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:27:41 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/03 12:58:28 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

// if (n == 0)
// 		return (0);
// 	do {
// 		if (*s1 != *s2++)
// 			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
// 		if (*s1++ == 0)
// 			break ;
// 	} while (--n != 0);
// 	return (0);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 != '\0' && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
