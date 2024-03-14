/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:26:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/14 16:34:43 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int _sorted(t_node *node)
{
  return (node->m_val > node->m_next->m_val);
}

int sorted(t_stack* stack)
{
  if (NULL == stack->m_head)
      return 1;
  return (traverse_unary_predicate(_sorted, stack->m_head));
}

t_node *_smallest(t_node *f, t_node *l)
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

int check_sorted(t_stack * const stack)
{
  t_node *pivot = smallest(stack);

  if (traverse_unary_predicate(_sorted, pivot))
  {
    while (stack->m_head != pivot)
    {
      rotate(stack);
    }
    return 1;
  }
  return 0;
}

int count = 1;

void sort_stacks(t_stack * const a, t_stack * const b)
{
  int tmp;

  while (!empty(a))
  {
    print_parallel(a, b);
    if (check_sorted(a) && peak(b) < peak(a))
    {
      break;
    }
    count++;
    tmp = pop(a);
    while (!empty(b) && peak(b) > tmp)
    {
      push_a_b(b, a);
    }
    push(tmp, b);
  }
  
  while (!empty(b))
  {
    print_parallel(a, b);
    count++;
    push(pop(b), a);
  }

  print_parallel(a, b);
  printf("Steps permitted : %d\n", count);
  clear(b);
}





