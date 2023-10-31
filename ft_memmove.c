/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:29:33 by jotomas-          #+#    #+#             */
/*   Updated: 2023/10/31 12:03:51 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str_dest;
	char	*str_src;

	str_dest = (char *)dest;
	str_src = (char *)src;
	if (str_dest <= str_src)
	{
		while (n--)
		{
			str_dest[n] = str_src[n];
		}
	}
	else
	{
		while (n--)
		{
			str_dest[n - 1] = str_src[n - 1];
		}
	}
	printf("sizeof: %lu\n", sizeof(str_dest));
	return (dest);
}
