/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:26:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/13 17:04:14 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int sorted(t_stack const * const stack)
{
  t_node *f = stack->m_head;
  t_node *s;
  if (stack->m_head == stack->m_tail)
    return (1);
  s = f->m_next;
  do 
  {
    if (s->m_val < f->m_val)
      return (0);
    s = s->m_next;
  }
  while (s != f);

  return (1);
}

void sort_stacks(t_stack * const a, t_stack * const b)
{
  int tmp;

  while (!sorted(a))
  {
    tmp = pop(a);
    while (!empty(b) && peak(b) > tmp)
    {
      push(pop(b), a);
    }
    push(tmp, b);
  }
}
