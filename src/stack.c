/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/14 18:49:13 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

#ifndef MAIN

int	main(int ac, char **av)
{
	t_stack	*a;

	a = a_init(ac, av);
  
 t_stack *b = stack_init();
  if (NULL == a)
	{
		printf("invalid input aper\n");
		return (-1);
  }


  sort_stacks(a, b);
  // print(a);

  destroy(&a);
  destroy(&b);

# ifdef DEBUG
  
  printf ("\n\n\nLeaks : \n");
	system("leaks push_swap");

# endif // DEBUG
}

#endif // MAIN
