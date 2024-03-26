/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:13:56 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/26 16:03:19 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	(*closest(t_stack *stack, t_node *end))(t_stack *const a, t_mode b)
{
	t_node	*t_head;
	t_node	*t_tail;

	t_head = stack->m_head;
	t_tail = stack->m_head->m_prev;
	while (t_head != end && t_tail != end)
	{
		t_head = t_head->m_next;
		t_tail = t_tail->m_prev;
	}
	if (t_head == end)
		return (rotate);
	return (rrotate);
}

void	organize_rotate(t_stack *const stack, t_node *end)
{
	void	(*f)(t_stack *const, t_mode);

	f = closest(stack, end);
	while (stack->m_head != end)
	{
		f(stack, visible);
	}
}

int	sorted(t_stack *const stack)
{
	t_node	*start;

	start = smallest(stack);
	if (fullsorted(stack))
	{
		return (1);
	}
	if (traverse_unary_predicate(_sorted, stack, start, start))
	{
		organize_rotate(stack, start);
		return (1);
	}
	return (0);
}

void	sort_stacks(t_stack *const a, t_stack *const b)
{
	while (!empty(a) && !(sorted(a) && (empty(b) || top(b) < top(a))))
	{
		organize_rotate(a, smallest(a));
		push_a_b(a, b);
	}
	while (!empty(b))
	{
		push_a_b(b, a);
	}
	clear(b);
}
