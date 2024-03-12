/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_the_same_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:31 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/12 21:25:49 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *const a, t_stack *const b)
{
	swap(a);
	swap(b);
}

void	rr(t_stack *const a, t_stack *const b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_stack *const a, t_stack *const b)
{
	rrotate(a);
	rrotate(b);
}
