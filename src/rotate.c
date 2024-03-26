/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/26 16:07:17 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *const stack, t_mode mode)
{
	if (!empty(stack))
	{
		stack->m_head = stack->m_head->m_next;
	}
	if (mode == visible)
		ft_printf("r%c\n", stack->m_name);
}

void	rrotate(t_stack *const stack, t_mode mode)
{
	if (!empty(stack))
	{
		stack->m_head = stack->m_head->m_prev;
	}
	if (mode == visible)
		ft_printf("rr%c\n", stack->m_name);
}
