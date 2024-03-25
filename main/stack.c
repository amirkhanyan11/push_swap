/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/25 17:46:48 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	__death_666___(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

#ifndef MAIN

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
  
  if (ac > 1)
  {
    a = a_init(ac, av, 'a');
    b = stack_init('b');
    if (NULL == a)
    {
      __death_666___();
    }
    sort_stacks(a, b);
    destroy(&a);
    destroy(&b);
  }
}

#endif // MAIN
