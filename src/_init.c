/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:15:16 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/12 17:15:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->m_head = NULL;
  stack->m_tail = NULL;
	return (stack);
}

t_node	*node_init(int const val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->m_val = val;
  node->m_next = NULL;
  node->m_prev = NULL;
	return (node);
}

