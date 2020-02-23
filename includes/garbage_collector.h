/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 11:23:25 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 11:23:30 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include <stdlib.h>
# include "asm.h"

typedef struct		s_mem
{
	void	**ptr;
	size_t	size;
	size_t	capacity;
}					t_mem;

void				init_gc(void);
void				*gmalloc(size_t size);
void				del_gc(void);

#endif
