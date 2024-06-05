#include "push_swap.h"

void printstack (t_stack *stack)
{
    while (stack)
    {
        printf ("%d\n", stack->data);
        stack = stack->next;
    }
}

int main (int ac , char **av)
{
    t_stack *a;
    t_stack *b;
    char **split = NULL;

    a = NULL;
    b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    else if (ac == 2)
        split = ft_split(av[1], ' ');
    init_stack_a (&a, split);

    if (!stack_sorted(a))
    {
        if (get_stack_size(a) == 2)
            sa(&a);
        else if (get_stack_size(a) == 3)
            sort_three(&a);
        else
            sort_stack (&a, &b);
    }
    printstack(a);
    free_stack(&b);
    return (0);
}

