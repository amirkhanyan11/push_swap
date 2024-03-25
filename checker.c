#include "./includes/push_swap.h"
#include <sys/fcntl.h>


void parce_push(t_stack *a, t_stack *b, char const * input)
{
  if (!ft_strncmp(input, "pa", ft_strlen(input) - 1))
    push_a_b(b, a);
  else if (!ft_strncmp(input, "pb", ft_strlen(input) - 1))
    push_a_b(a, b);
}


void parce_rotate(t_stack *a, t_stack *b, char const * input)
{
  if (!ft_strncmp(input, "ra", ft_strlen(input) - 1))
    rotate(a, visible);
  else if (!ft_strncmp(input, "rb", ft_strlen(input) - 1))
    rotate(b, visible);
  else if (!ft_strncmp(input, "rra", ft_strlen(input) - 1))
    rrotate(a, visible);
  else if (!ft_strncmp(input, "rrb", ft_strlen(input) - 1))
    rrotate(b, visible);
  else if (!ft_strncmp(input, "rr", ft_strlen(input) - 1))
    rr(a, b);
  else if (!ft_strncmp(input, "rrr", ft_strlen(input) - 1))
    rrr(a, b); 
}


void parce_swap (t_stack *a, t_stack *b, char const * input)
{
  if (!ft_strncmp(input, "sa", ft_strlen(input) - 1))
    swap(a, visible);
  else if (!ft_strncmp(input, "sb", ft_strlen(input) - 1))
    swap(b, visible);
  else if (!ft_strncmp(input, "ss", ft_strlen(input) - 1))
    ss(a, b);
}

void parce (t_stack *a, t_stack *b, char const * input)
{
  parce_push(a, b, input);
  parce_rotate(a, b, input);
  parce_swap(a, b, input);
};

void handle(t_stack *a, t_stack *b)
{
  char * input = get_next_line(0);
  while (input)
  {
    parce(a, b, input);
    free(input);
    input = get_next_line(0);
  }
}


int main(int ac, char ** av)
{
	t_stack	*a;

	a = a_init(ac, av, 'a');
  
  t_stack *b = stack_init('b');

  handle(a, b);

  if (fullsorted(a) == 1)
    printf("OK\n");
  else
    printf("KO\n");
 
  return 0;
}
