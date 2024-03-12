
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/12 19:20:08 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pop(t_stack *const stack)
{
	t_node	*next;

	if (empty(stack))
		return ;
	next = stack->m_head->m_next;
	stack->m_tail->m_next = stack->m_head->m_next;
	stack->m_head->m_next->m_prev = stack->m_tail;
	free(stack->m_head);
	stack->m_head = next;
}
