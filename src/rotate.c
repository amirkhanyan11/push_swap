/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/20 20:27:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void rotate(t_stack * const stack, t_mode mode)
{
	if (!empty(stack))
	{
		stack->m_head = stack->m_head->m_next;
	}
  
  if (mode == single)
    printf("r%c\n", stack->m_name);
}

void rrotate(t_stack * const stack, t_mode mode)
{
	if (!empty(stack))
	{
		stack->m_head = stack->m_head->m_prev;
	}
  
  if (mode == single)
    printf("rr%c\n", stack->m_name);
}
