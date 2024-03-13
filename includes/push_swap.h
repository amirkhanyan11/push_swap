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
#include <stdint.h>
#include <stdio.h>

// #define MAIN
/* #define DEBUG */

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
  invalid_input = 2147483650
} t_input;

typedef void	(*fptr)(t_node *);
typedef int(*unary_predicate)(t_node *);
typedef t_node*(*cmp)(t_node *, t_node *);


// stack methods
void sort_stacks(t_stack * const a, t_stack * const b);
t_stack	*stack_init(void);
t_node	*node_init(int const val);
t_stack *a_init(int ac, char **av);
t_node *find(int const val, t_stack *stack);
int peak(t_stack * const stack);
void	push(int const val, t_stack * const stack);
void traverse(fptr f, t_node *head);
int traverse_unary_predicate(unary_predicate f, t_node *head);
t_node  *traverse_binary_predicate(cmp f, t_node *head);
void print(t_stack * stack); 
void clear(t_stack * stack);
int empty(t_stack * const stack);
void swap(t_stack * const stack);
int pop(t_stack * const stack);
void push_a_b(t_stack * const a, t_stack * const b);
void rotate(t_stack * const stack);
void rrotate(t_stack * const stack);

// debil functions
void ss(t_stack * const a, t_stack *const b);
void rr(t_stack * const a, t_stack *const b);
void rrr(t_stack * const a, t_stack *const b);

// error handling
int alloc_nums(int ac, char **av, t_stack *stack);
void free_mat(char **mat);














