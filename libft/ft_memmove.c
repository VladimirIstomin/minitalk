/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:52:20 by gmerlene          #+#    #+#             */
/*   Updated: 2021/10/15 09:43:03 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const char *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if ((char *)dst < src)
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = src[i];
			i++;
		}	
	}
	else
	{
		i = len - 1;
		while (i <= len)
		{
			((char *)dst)[i] = src[i];
			i--;
		}
	}
	return (dst);
}
