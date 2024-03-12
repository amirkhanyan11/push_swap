/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:28:28 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/12 19:43:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include <stdio.h>

// #define MAIN
#define DEBUG

typedef struct s_node
{
	int			m_val;
	struct s_node		*m_next;
	struct s_node		*m_prev;

}				t_node;

typedef struct s_stack
{
	t_node		*m_head;
	t_node		*m_tail;

}				t_stack;

typedef enum e_input
{
  invalid_input = SIZE_MAX
} t_input;

typedef void	(*fptr)(t_node *);

// stack methods
t_stack	*stack_init(void);
t_node	*node_init(int const val);
t_node *find(int const val, t_stack *stack);
void	push(int const val, t_stack * const obj);
void traverse(fptr f, t_node *head);
void print(t_stack * stack); 
void clear(t_stack * stack);
int empty(t_stack * const stack);
void swap(t_stack * const stack);
void pop(t_stack * const stack);
void push_a_b(t_stack * const a, t_stack * const b);
void rotate(t_stack * const stack);
void rrotate(t_stack * const stack);

// debil functions
void ss(t_stack * const a, t_stack *const b);
void rr(t_stack * const a, t_stack *const b);
void rrr(t_stack * const a, t_stack *const b);

// error handling
t_stack *a_init(int ac, char **av);
size_t _atoi(char const * const str);
void free_mat(char **mat);
int alloc_nums(int ac, char **av, t_stack *stack);
void free_mat(char **mat);














