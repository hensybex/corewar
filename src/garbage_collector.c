/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 05:36:07 by lreznak-          #+#    #+#             */
/*   Updated: 2020/01/31 20:58:42 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "garbage_collector.h"
#include <unistd.h>

t_mem		g_garbage_collector;

#define INIT_CAPACITY	5
#define KOEF			2

void			init_gc(void)
{
	g_garbage_collector.size = 0;
	g_garbage_collector.capacity = INIT_CAPACITY;
	g_garbage_collector.ptr = (void **)malloc(sizeof(void *) * INIT_CAPACITY);
}

static void		append_mem(void *ptr)
{
	void	*tmp;

	if (g_garbage_collector.size < g_garbage_collector.capacity)
	{
		g_garbage_collector.ptr[g_garbage_collector.size] = ptr;
		g_garbage_collector.size++;
	}
	else
	{
		tmp = malloc(g_garbage_collector.capacity * KOEF * sizeof(void *));
		g_garbage_collector.capacity *= KOEF;
		ft_memcpy(tmp,
				g_garbage_collector.ptr, sizeof(void *) *
				g_garbage_collector.size);
		free(g_garbage_collector.ptr);
		g_garbage_collector.ptr = tmp;
		g_garbage_collector.ptr[g_garbage_collector.size] = ptr;
		g_garbage_collector.size++;
	}
}

void			*gmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		write(2, "Memory was not allocated\n", 25);
		exit(1);
	}
	append_mem(ptr);
	return (ptr);
}

void			del_gc(void)
{
	size_t		i;

	i = 0;
	while (i < g_garbage_collector.size)
	{
		free(g_garbage_collector.ptr[i]);
		i++;
	}
	free(g_garbage_collector.ptr);
}
