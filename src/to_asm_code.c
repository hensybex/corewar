/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_asm_code2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:39:39 by smanhack          #+#    #+#             */
/*   Updated: 2020/01/31 12:41:51 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		fill_code(t_parse *champ)
{
	t_command	*buff;
	size_t		i;

	i = 0;
	buff = champ->list_cmd;
	while (buff != NULL)
	{
		champ->exec_code[i++] = g_op[buff->type].code;
		if (g_op[buff->type].args_types_code)
			champ->exec_code[i++] = args_type_code(buff);
		i = add_arg(buff, i, champ);
		buff = buff->next;
	}
}

void		to_asm_code(t_parse *champ)
{
	t_command	*buff;
	int			i;

	buff = champ->list_cmd;
	while (buff != NULL)
	{
		champ->size += sizing(buff);
		buff = buff->next;
	}
	if (!(champ->exec_code = (uint8_t *)malloc(sizeof(uint8_t) * champ->size)))
		error("Память не выделилась!", -1);
	i = 0;
	while (i < champ->size)
		champ->exec_code[i++] = 0;
	fill_code(champ);
}
