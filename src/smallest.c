/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:13:45 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/26 16:03:19 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_sorted(t_node *node)
{
	return (node->m_val > node->m_next->m_val);
}

int	fullsorted(t_stack *stack)
{
	if (NULL == stack->m_head)
		return (1);
	return (traverse_unary_predicate(_sorted, stack, stack->m_head,
			stack->m_head));
}

t_node	*_smallest(t_node *f, t_node *l)
{
	if (f->m_val < l->m_val)
		return (f);
	return (l);
}

t_node	*smallest(t_stack *const stack)
{
	if (empty(stack))
		return (NULL);
	return (traverse_binary_predicate(_smallest, stack->m_head));
}
