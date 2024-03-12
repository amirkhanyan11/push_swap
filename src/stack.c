/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/12 21:23:12 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

void	push(int const val, t_stack * const obj)
{
	t_node	*new_node;

	new_node = node_init(val);
  new_node->m_next = obj->m_head;

	if (!empty(obj))
	   obj->m_head->m_prev = new_node;

	obj->m_head = new_node;
  
  if (obj->m_tail == NULL)
    obj->m_tail = obj->m_head;
  
  obj->m_tail->m_next = obj->m_head;
  obj->m_head->m_prev = obj->m_tail;
}

void swap(t_stack * const stack)
{
	t_node* to_swap = stack->m_head->m_next;

	if (to_swap == stack->m_tail)
		stack->m_tail = stack->m_head;
	else
		to_swap->m_next->m_prev = stack->m_head;

	to_swap->m_prev = stack->m_tail;
	stack->m_head->m_prev = to_swap;

	stack->m_head->m_next = to_swap->m_next;
	to_swap->m_next = stack->m_head;
  
  stack->m_head = to_swap;

  stack->m_tail->m_next = stack->m_head;
}


t_node *find(int const val, t_stack *stack)
{
  if (empty(stack))
    return (NULL);
  t_node *l = stack->m_head;
  t_node *f = l;
  
  do 
  {
    if (f->m_val == val)
    {
      return (f);
    }
    f = f->m_next;
  }
  while(f != l);
  return (NULL);
}

void pop(t_stack * const stack)
{
  if (empty(stack))
    return;
  
  t_node *next = stack->m_head->m_next;

  stack->m_tail->m_next = stack->m_head->m_next;
  stack->m_head->m_next->m_prev = stack->m_tail;
  free(stack->m_head);
  stack->m_head = next;
}

void push_a_b(t_stack * const lhv, t_stack * const rhv)
{
  int val = lhv->m_head->m_val;

  pop(lhv);

  push(val, rhv);
}


void rotate(t_stack * const stack)
{
  if (!empty(stack))
  {
    stack->m_head = stack->m_head->m_next;
    stack->m_tail = stack->m_tail->m_next;
  }
}


void rrotate(t_stack * const stack)
{
  if (!empty(stack))
  {
    stack->m_head = stack->m_head->m_prev;
    stack->m_tail = stack->m_tail->m_prev;
  }
}

#ifndef MAIN

int main(int ac, char **av)
{
  t_stack *a;

  a = a_init(ac, av);
  if (NULL == a)
  {
    printf("invalid input aper\n");
    return (-1);
  }

  print(a);
  clear(a);


#ifdef DEBUG
  system("leaks push_swap");
#endif // DEBUG
}


#endif // MAIN



