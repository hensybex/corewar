/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:43:05 by smanhack          #+#    #+#             */
/*   Updated: 2019/12/25 03:14:00 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
    char			*ptr1;
    char			*ptr2;
    unsigned int	i;

    i = 0;
    if (dst == src)
        return (dst);
    ptr1 = (char*)dst;
    ptr2 = (char*)src;
    while (i < n)
    {
        ptr1[i] = ptr2[i];
        i++;
    }
    return (dst);
}
/*void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*s;
	unsigned long	*d;
	unsigned char	*sc;
	unsigned char	*dc;
	size_t			nb;

	d = (unsigned long *)dst;
	s = (unsigned long *)src;
	nb = n / sizeof(unsigned long);
	while (nb--)
		*(d++) = *(s++);
	nb = n % sizeof(unsigned long);
	sc = (unsigned char *)s;
	dc = (unsigned char *)d;
	while (nb--)
		*(dc++) = *(sc++);
	return (dst);
}*/
