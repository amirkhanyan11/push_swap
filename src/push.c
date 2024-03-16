/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:15:40 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/16 18:35:42 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	push(int const val, t_stack *const obj)
{
	t_node	*new_node;

	new_node = node_init(val);
	new_node->m_next = obj->m_head;

  if (empty(obj))
  {
    obj->m_head = new_node;
    obj->m_head->m_next = new_node;
    obj->m_head->m_prev = new_node;
    return;
  }	
	
  obj->m_head->m_prev->m_next = new_node;
  new_node->m_prev = obj->m_head->m_prev;
  obj->m_head->m_prev = new_node;
	obj->m_head = new_node;
}


void	push_a_b(t_stack *const lhv, t_stack *const rhv)
{
	int	val;

	val = pop(lhv);
	push(val, rhv);


  printf("p%c ", lhv->m_name);
}



