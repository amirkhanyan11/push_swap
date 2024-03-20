/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/20 20:32:00 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef MAIN

int	main(int ac, char **av)
{
	t_stack	*a;

	a = a_init(ac, av, 'a');
  
 t_stack *b = stack_init('b');
  if (NULL == a)
	{
		printf("invalid input aper\n");
		return (-1);
  }


  sort_stacks(a, b);

  // if (sorted(a))
  //     printf("Success!!\n");
  // else 
  //   printf("Not sorted!\n");

  destroy(&a);
  destroy(&b);

# ifdef DEBUG
  
  printf ("\n\n\nLeaks : \n");
	system("leaks push_swap");

# endif // DEBUG
}

#endif // MAIN
