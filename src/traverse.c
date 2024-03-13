/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:16:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/13 20:27:21 by aamirkha         ###   ########.fr       */
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

int traverse_predicate(unary_predicate f, t_node *head)
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
	} while (head != breakpoint);

  return 1;
}

void	print(t_stack *stack)
{
	traverse(_print, stack->m_head);
  printf("\n");
}

void	clear(t_stack *stack)
{
	traverse(_clear, stack->m_head);
  stack->m_head = NULL;
  stack->m_tail = NULL;
}

int	empty(t_stack *stack)
{
	return (stack->m_head == NULL);
}
