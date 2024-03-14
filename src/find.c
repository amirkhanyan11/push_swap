/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:18:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/14 20:39:29 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find(int const val, t_stack *stack)
{
	t_node	*l;
	t_node	*f;

	if (empty(stack))
		return (NULL);
	l = stack->m_head;
	f = l;
	do
	{
		if (f->m_val == val)
		{
			return (f);
		}
		f = f->m_next;
	} while (f != l);
	return (NULL);
}

