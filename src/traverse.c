/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:16:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/25 17:41:17 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	_print(t_node *node)
{
	printf("%d  ", node->m_val);
}

static void	_clear(t_node *const node)
{
	free(node);
}

void	traverse(fptr f, t_node *head)
{
	t_node	*end;
	t_node	*tmp;
  
  if (NULL == head)
      return;
	end = head;
	do
	{
		tmp = head->m_next;
		f(head);
		head= tmp;
	} while (head != end);
}


t_node* traverse_binary_predicate(cmp f, t_node *head)
{
  t_node	*end;
	t_node	*pivot;
  
  if (NULL == head)
      return NULL;
	end = head;
  pivot = head;
	do
	{
	  pivot = f(head, pivot);
    head = head->m_next;
	} while (head != end);

  return pivot;
}


size_t distance(t_node * f, t_node * l)
{
  t_node * end = f;
  size_t distance = 0;

  do 
  {
    distance++;
    f = f->m_next;
  }
  while (f != l && f != end);

  return distance;
}

int traverse_unary_predicate(unary_predicate f, t_stack * const stack, t_node *start, t_node *end)
{
	t_node	*tmp;

  if (NULL == start || start->m_next == end)
      return 1;
	do
	{
		tmp = start->m_next;
		if (f(start))
    {
      if (start == stack->m_head && (start->m_val < start->m_next->m_next->m_val || (start->m_prev == start->m_next->m_next && start->m_next->m_val > start->m_prev->m_val))
      && traverse_unary_predicate(f, stack, start->m_next->m_next, stack->m_head))
      {
        swap(stack, visible);
        return fullsorted(stack);
      }
      return 0;
    }
		start = tmp;
	} while (start->m_next != end);

  return 1;
}

void	print(t_stack *stack)
{
	traverse(_print, stack->m_head);
  printf("\n");
}



void print_parallel_helper(long long a, long long b)
{
  if (a == invalid_input && b == invalid_input)
    printf ("   \n");
  else if (a != invalid_input && b == invalid_input)
    printf ("%lld   \n", a);
  else if(a == invalid_input && b != invalid_input)
    printf ("   %lld\n", b);
  else
    printf ("%lld   %lld\n", a, b);
}

void print_parallel(t_stack *a, t_stack*b)
{
  if (NULL == a || NULL == b)
      return;

  t_node *t_a = a->m_head;
  t_node *t_b = b->m_head;
  long long val_a, val_b;
  int flag = 0;
  
  printf("\n");

  printf("------------------------\n");
  do 
  {
    val_a = invalid_input;
    val_b = invalid_input;

    if (t_b == b->m_head && t_a != a->m_head)
        flag = 1;

    if (NULL != t_a)
      val_a = t_a->m_val;

    if (NULL != t_b && !flag)
      val_b = t_b->m_val;

    print_parallel_helper(val_a, val_b);
    
    if (NULL != t_a)
      t_a = t_a->m_next;
    if (NULL != t_b)
      t_b = t_b->m_next;
  }
  while (t_a != a->m_head);

  printf ("_   _\n");
  printf ("a   b\n");
}

void	clear(t_stack *stack)
{
	traverse(_clear, stack->m_head);
  stack->m_head = NULL;
}

int	empty(t_stack *stack)
{
	return (stack->m_head == NULL);
}
