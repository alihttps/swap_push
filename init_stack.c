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

    i = 0;
    while (av[i])
    {
        // if (error_syntax(av[i]))
        //     free_error(a);
        n = ft_atol(av[i]);
        // if (n > INT_MAX || n < INT_MIN)
        //     free_error(a);
        // if (error_duplicate(*a, (int)n))
        //     free_error(a);
        add_bottom(a, n);
        i++;
    }
}

