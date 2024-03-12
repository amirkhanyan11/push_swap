/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:34:41 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/12 18:45:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


#ifdef MAIN

// #define DEBUG

int main()
{
  t_stack *stack = stack_init();


  push(4, stack);
  push(3, stack);
push(2, stack);
  push(1, stack);

// pop(stack);
// swap(stack);
  
  rotate(stack);
  rotate(stack);
  rotate(stack);

  print(stack);
  clear(stack);
  
#ifdef DEBUG
  system("leaks push_swap");
#endif // DEBUG
}

#endif // MAIN
