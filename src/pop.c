
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

int pop(t_stack *const stack)
{
	t_node	*next;
  long long val;


	if (empty(stack))
		return (-1);
  
  val = stack->m_head->m_val;

  if (stack->m_head == stack->m_tail)
  {
    clear(stack);
  }
  
  else 
  {
    next = stack->m_head->m_next;
    stack->m_tail->m_next = next;
    next->m_prev = stack->m_tail;
    free(stack->m_head);
    stack->m_head = next;    
  }

  return (val);
}
