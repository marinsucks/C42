/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:38:46 by mbecker           #+#    #+#             */
/*   Updated: 2023/10/30 16:38:50 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*ptr;

	ptr = s1;
	while (*s1 != 0)
		s1++;
	while (*s2 != 0 && (int)n > 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	*s1 = 0;
	return (ptr);
}
