/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:18:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/14 18:35:47 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	swap(t_stack *const stack)
{
  int val;

  if (stack->m_head == NULL || stack->m_head->m_next == NULL)
  {
    return ;
  }

  val = stack->m_head->m_val;
  stack->m_head->m_val = stack->m_head->m_next->m_val;
  stack->m_head->m_next->m_val = val;
}

