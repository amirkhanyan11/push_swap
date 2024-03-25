/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peak.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:10:41 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/25 19:23:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	peak(t_stack *const stack)
{
	if (empty(stack))
	{
		return (invalid_input);
	}
	return (stack->m_head->m_val);
}
