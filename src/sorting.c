
#include "../includes/push_swap.h"

int _sorted(t_node *node)
{
  return (node->m_val > node->m_next->m_val);
}

int sorted(t_stack* stack)
{
  if (NULL == stack->m_head)
      return 1;
  return (traverse_unary_predicate(_sorted, stack, stack->m_head));
}

t_node *_smallest(t_node *f, t_node *l)
{
  if (f->m_val < l->m_val)
      return f;
  return l;
}

static t_node *smallest(t_stack * const stack)
{
  if (empty(stack))
      return NULL;

  return (traverse_binary_predicate(_smallest, stack->m_head));
}

int count = 0;

void (*closest(t_stack *stack, t_node *pivot))(t_stack * const, t_mode)
{
  t_node *t_head = stack->m_head;
  t_node *t_tail = stack->m_head->m_prev;

  while (t_head != pivot && t_tail != pivot)
  {
    if (t_head == pivot)
        return rotate;
    t_head = t_head->m_next;
    t_tail = t_tail->m_prev;
  }
  return rrotate;
}

void organize_rotate(t_stack * const stack, t_node* end)
{
  void (*f)(t_stack * const, t_mode) = closest(stack, end);
  while (stack->m_head != end)
  {
    f(stack, single);
    count++;
  }
}

int check_sorted(t_stack * const stack)
{
  t_node *pivot = smallest(stack);

  if (traverse_unary_predicate(_sorted, stack, pivot))
  {
    organize_rotate(stack, pivot);
    return 1;
  }
  return 0;
}


void sort_stacks(t_stack * const a, t_stack * const b)
{
  int tmp;

  while (!empty(a))
  {
    // print_parallel(a, b);
    if (check_sorted(a) && (empty(b) || peak(b) < peak(a)))
    {
      break;
    }
    count++;
    organize_rotate(a, smallest(a));
    push_a_b(a, b);
  }
  
  while (!empty(b))
  {
    // print_parallel(a, b);
    push_a_b(b, a);
    count++;
  }

//  print_parallel(a, b);
  // printf("\nSteps permitted : %d\n", count);
  clear(b);
}





