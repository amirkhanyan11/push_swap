/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:08 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/12 19:22:16 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

#ifndef MAIN

int	main(int ac, char **av)
{
	t_stack	*a;

	a = a_init(ac, av);

  if (NULL == a)
	{
		printf("invalid input aper\n");
		return (-1);
  }
	
  print(a);
	clear(a);

# ifdef DEBUG
	system("leaks push_swap");
# endif // DEBUG
}

#endif // MAIN