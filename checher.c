#include "./includes/push_swap.h"
#include <sys/fcntl.h>


void parce (t_stack *a, t_stack *b, char const * input)
{
  if (!ft_strncmp(input, "pa\n", ft_strlen(input)))
    push_a_b(b, a);
  else if (!ft_strncmp(input, "pb\n", ft_strlen(input)))
    push_a_b(a, b);
  else if (!ft_strncmp(input, "ra\n", ft_strlen(input)))
    rotate(a, single);
  else if (!ft_strncmp(input, "rra\n", ft_strlen(input)))
    rrotate(a, single);
};


void handle(t_stack *a, t_stack *b, int fd)
{
  
  char * input = get_next_line(fd);
  while (input)
  {
    parce(a, b, input);
    free(input);
    input = get_next_line(fd);
  }
}


int main(int ac, char ** av)
{
	t_stack	*a;

  int fd = open("esh.txt", O_RDONLY);
	a = a_init(ac, av, 'a');
  
  t_stack *b = stack_init('b');

  handle(a, b, fd);

  if (check_sorted(a) == 1)
    printf("OK\n");
  else
    printf("KO\n");
 
  return 0;
}
