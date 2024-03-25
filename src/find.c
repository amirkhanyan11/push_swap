/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:18:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/25 19:12:42 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find(int const val, t_stack *stack)
{
	t_node	*l;
	t_node	*f;

	if (empty(stack))
		return (NULL);
	l = stack->m_head->m_prev;
	f = stack->m_head;
	while (f != l)
	{
		if (f->m_val == val)
			return (f);
		f = f->m_next;
	}
	if (l->m_val == val)
		return (l);
	return (NULL);
}

void	print(t_stack *stack)
{
	traverse(_print, stack->m_head);
	printf("\n");
}

void	clear(t_stack *stack)
{
	traverse(_clear, stack->m_head);
	stack->m_head = NULL;
}

int	empty(t_stack *stack)
{
	return (stack->m_head == NULL);
}
