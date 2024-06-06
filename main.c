#include "push_swap.h"

void printstack (t_stack *stack)
{
    while (stack)
    {
        printf ("%d\n", stack->data);
        stack = stack->next;
    }
}

char **process_input(int ac, char **av) {
    char **split;
    char *joined;

    joined = arg_join(ac, av);
    split = ft_split(joined, ' ');
    free(joined);

    if (!correct_input(split)) 
    {
        ft_putstr("error");
        free_split(split);
        return NULL;
    }
    return split;
}

int main (int ac , char **av)
{
    t_stack *a;
    t_stack *b;
    char **split;

    a = NULL;
    b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    else if (ac > 2)
    {
        split = process_input(ac, av);
        if (!split)
            return 1;
    }
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
    free_stack(&a);
    free_stack(&b);
    return (0);
}
