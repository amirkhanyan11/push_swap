/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:26:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/13 20:33:03 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int _sorted(t_node *node)
{
  return (node->m_val > node->m_prev->m_val);
}

int sorted(t_stack* stack)
{
  if (NULL == stack->m_head)
      return 1;
  return (traverse_unary_predicate(_sorted, stack->m_head->m_next));
}

static t_node *_smallest(t_node *f, t_node *l)
{
  if (f->m_val < l->m_val)
      return f;
  return l;
}

static t_node *smallest(t_stack * const stack)
{
  if (empty(stack))
      return NULL;

  return (traverse_binary_predicate(_smallest, stack->m_head));
}

int count = 1;

void sort_stacks(t_stack * const a, t_stack * const b)
{
  int tmp;

  while (!empty(a))
  {
    printf("count : %d\n", count++);
    tmp = pop(a);
    while (!empty(b) && peak(b) > tmp)
    {
      push_a_b(b, a);
    }
    push(tmp, b);
  }
  
  while (!empty(b))
  {
    printf("count : %d\n", count++);
    push(pop(b), a);
  }
}





