/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:16:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/14 18:37:11 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	t_node	*breakpoint;
	t_node	*tmp;
  
  if (NULL == head)
      return;
	breakpoint = head;
	do
	{
		tmp = head->m_next;
		f(head);
		head= tmp;
	} while (head != breakpoint);
}


t_node* traverse_binary_predicate(cmp f, t_node *head)
{
  t_node	*breakpoint;
	t_node	*pivot;
  
  if (NULL == head)
      return NULL;
	breakpoint = head;
  pivot = head;
	do
	{
	  pivot = f(head, pivot);
    head = head->m_next;
	} while (head != breakpoint);

  return pivot;
}

int traverse_unary_predicate(unary_predicate f, t_node *head)
{
  t_node	*breakpoint;
	t_node	*tmp;
  
  if (NULL == head)
      return 1;
	breakpoint = head;
	do
	{
		tmp = head->m_next;
		if (f(head))
      return 0;
		head = tmp;
	} while (head->m_next != breakpoint);

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
