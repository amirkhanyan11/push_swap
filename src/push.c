/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:15:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/21 16:10:34 by aamirkha         ###   ########.fr       */
/*   Updated: 2024/03/15 23:39:20 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(int const val, t_stack *const stack)
{
	t_node	*new_node;

	new_node = node_init(val);
	new_node->m_next = stack->m_head;

  if (empty(stack))
  {
    stack->m_head = new_node;
    stack->m_head->m_next = new_node;
    stack->m_head->m_prev = new_node;
    return;
  }	
	
  stack->m_head->m_prev->m_next = new_node;
  new_node->m_prev = stack->m_head->m_prev;
  stack->m_head->m_prev = new_node;
	stack->m_head = new_node;
}


void	push_a_b(t_stack *const lhv, t_stack *const rhv)
{
	int	val;

	val = pop(lhv);
	push(val, rhv);


  printf("p%c\n", rhv->m_name);
}



