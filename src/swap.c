/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:18:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/26 16:07:17 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *const stack, t_mode mode)
{
	int	val;

	if (stack->m_head == NULL || stack->m_head == stack->m_head->m_next)
	{
		return ;
	}
	val = stack->m_head->m_val;
	stack->m_head->m_val = stack->m_head->m_next->m_val;
	stack->m_head->m_next->m_val = val;
	if (mode == visible)
		ft_printf("s%c\n", stack->m_name);
}
