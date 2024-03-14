/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peak.c                                             :+:      :+:    :+:   *//*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:49:37 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/13 16:56:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int peak(t_stack * const stack)
{
  if (empty(stack))
  {
    return (invalid_input);
  }
  return (stack->m_head->m_val);
}
