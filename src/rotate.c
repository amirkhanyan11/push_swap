/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/14 18:31:28 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack *const stack)
{
	if (!empty(stack))
	{
		stack->m_head = stack->m_head->m_next;
	}
}

void	rrotate(t_stack *const stack)
{
	if (!empty(stack))
	{
		stack->m_head = stack->m_head->m_prev;
	}
}
