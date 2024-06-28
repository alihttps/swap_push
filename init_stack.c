#include "push_swap.h"

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (is_digit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void init_stack_a (t_stack **a, char **av)
{
    long n;
    int i;
	t_stack *new;
    i = 0;
    while (av[i])
    {
        n = ft_atol(av[i]);
        if (n > INT_MAX || n < INT_MIN)
		{
            free_stack(a);
			ft_putstr("error");
		}
		if (i == 0)
			*a = create_node(n);
		else
        	add_bottom(a, create_node(n));
        i++;
    }
}
