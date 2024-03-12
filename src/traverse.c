/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:16:18 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/12 21:25:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	_print(t_node *node)
{
	printf("%d\n", node->m_val);
}

static void	_clear(t_node *const node)
{
	free(node);
}

void	traverse(fptr f, t_node *head)
{
	t_node	*breakpoint;
	t_node	*tmp;

	breakpoint = head;
	do
	{
		tmp = head->m_next;
		f(head);
		head = tmp;
	} while (head != breakpoint);
}

void	print(t_stack *stack)
{
	traverse(_print, stack->m_head);
}

void	clear(t_stack *stack)
{
	traverse(_clear, stack->m_head);
}

int	empty(t_stack *stack)
{
	return (stack->m_head == NULL);
}
