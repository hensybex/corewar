/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeljoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:27:43 by smanhack          #+#    #+#             */
/*   Updated: 2020/01/31 15:28:09 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdeljoin(char *s1, char *s2)
{
	char	*mem;
	int		len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	mem = (char *)malloc(sizeof(*mem) * len);
	if (mem == NULL)
		return (NULL);
	ft_strcpy(mem, s1);
	ft_strcat(mem, s2);
	ft_strdel(&s1);
	return (mem);
}
