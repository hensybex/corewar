/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:26:51 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 11:18:33 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

uint8_t		args_type_code(t_command *buff)
{
	uint8_t	byte;
	size_t	i;

	byte = 0;
	i = 0;
	while (i < 3)
	{
		if (buff->arg[i])
		{
			if (*(buff->arg[i]) == 'r')
				byte |= REG_CODE;
			else if (*(buff->arg[i]) == DIRECT_CHAR)
				byte |= DIR_CODE;
			else
				byte |= IND_CODE;
		}
		byte = byte << 2;
		i++;
	}
	return (byte);
}

void		mem_cpy(void *dst, void *src, int n)
{
	char			*ptr1;
	char			*ptr2;
	int				i;

	i = 0;
	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	while (i < n)
	{
		ptr1[i] = ptr2[n - 1 - i];
		i++;
	}
}

void		add_arg_dir(t_command *buff, size_t *i, t_parse *champ, size_t j)
{
	int16_t	num16;
	int32_t	num32;
	char	*str;

	num16 = 0;
	num32 = 0;
	str = buff->arg[j] + 1;
	if (g_op[buff->type].t_dir_size == 4)
	{
		num32 = ft_atoi(str);
		mem_cpy(champ->exec_code + *i, &num32, g_op[buff->type].t_dir_size);
	}
	else
	{
		num16 = ft_atoi(str);
		mem_cpy(champ->exec_code + *i, &num16, g_op[buff->type].t_dir_size);
	}
	*i += g_op[buff->type].t_dir_size;
}

void		add_arg_ind(t_command *buff, size_t *i, t_parse *champ, size_t j)
{
	char	*str;
	int16_t	num16;

	num16 = 0;
	str = buff->arg[j];
	num16 = ft_atoi(str);
	mem_cpy(champ->exec_code + *i, &num16, 2);
	*i += 2;
}

size_t		add_arg(t_command *buff, size_t i, t_parse *champ)
{
	size_t	j;
	char	*str;

	j = 0;
	while (j < g_op[buff->type].args_num)
	{
		if (buff->arg[j])
		{
			if (*(buff->arg[j]) == 'r')
			{
				str = buff->arg[j] + 1;
				champ->exec_code[i++] = (uint8_t)ft_atoi(str);
			}
			else if (*(buff->arg[j]) == DIRECT_CHAR)
				add_arg_dir(buff, &i, champ, j);
			else
				add_arg_ind(buff, &i, champ, j);
		}
		j++;
	}
	return (i);
}
