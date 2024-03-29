/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:15:16 by aamirkha          #+#    #+#             */
/*   Updated: 2024/03/26 16:02:20 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(char const name)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->m_head = NULL;
	stack->m_name = name;
	return (stack);
}

t_node	*node_init(int const val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->m_val = val;
	node->m_next = NULL;
	node->m_prev = NULL;
	return (node);
}

void	destroy(t_stack **stack)
{
	clear(*stack);
	free(*stack);
	*stack = NULL;
}

static int	_ac_count(char **mat)
{
	int	count;

	count = 0;
	while (mat[count])
	{
		count++;
	}
	return (count);
}

t_stack	*a_init(int ac, char **av, char const name)
{
	char	**mat;
	t_stack	*stack;

	stack = stack_init(name);
	mat = NULL;
	if (ac == 2)
	{
		mat = ft_split(av[1], ' ');
		if (alloc_nums(_ac_count(mat), mat, stack) == -1)
		{
			free_mat(mat);
			destroy(&stack);
			return (NULL);
		}
	}
	else if (ac < 2 || alloc_nums(ac - 1, av + 1, stack) == -1)
	{
		destroy(&stack);
		return (NULL);
	}
	free_mat(mat);
	return (stack);
}
