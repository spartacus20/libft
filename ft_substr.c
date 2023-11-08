/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:55:20 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/07 15:29:18 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s || len == 0)
		return (NULL);
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len);
	return (substr);
}
