/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:30:04 by smanhack          #+#    #+#             */
/*   Updated: 2020/01/24 20:15:24 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_itoa(long long n)
{
	int	len;

	len = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(long long n)
{
	unsigned int	size;
	char			*p;
	int				fl;

	size = ft_len_itoa(n);
	fl = 1;
	if (n < 0)
	{
		size++;
		fl = -1;
	}
	p = (char *)malloc(sizeof(*p) * (size + 1));
	if (!p)
		return (NULL);
	p[size--] = '\0';
	p[size--] = (fl * (n % 10)) + '0';
	n /= 10;
	while (n)
	{
		p[size--] = (fl * (n % 10)) + '0';
		n /= 10;
	}
	if (fl == -1)
		p[0] = '-';
	return (p);
}
