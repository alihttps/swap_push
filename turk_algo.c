#include "push_swap.h" 

void init_nodes_a(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_calculation_a(a, b);
    set_cheapest(a);
}

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = get_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b; 
	t_stack	*target_node;
	long			best_match_index; 

	while (a) 
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b) 
		{
			if (current_b->data < a->data && current_b->data > best_match_index) 
			{
				best_match_index = current_b->data; 
				target_node = current_b; 
			}
			current_b = current_b->next; 
		}
		if (best_match_index == LONG_MIN) 
			a->target = find_max_value(b); 
		else
			a->target = target_node; 
		a = a->next; 
	}
}

void cost_calculation_a (t_stack *a, t_stack *b)
{
    int	len_a;
	int	len_b;

	len_a = get_stack_size(a);
	len_b = get_stack_size(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = len_a - (a->index);
		if (a->target->above_median)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index); 
		a = a->next; 
	}
}

void set_cheapest(t_stack *stack)
{
    long			cheapest_value;
	t_stack	        *cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next; 
	}
	cheapest_node->cheapest = true;
}
t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median)) 
		reverse_rotate_both(a, b, cheapest_node); 
	prep_for_push(a, cheapest_node, 'a'); 
	prep_for_push(b, cheapest_node->target, 'b');
	pb(b, a);
}

void push_b_to_a (t_stack **a, t_stack **b)
{
    prep_for_push(a, (*b)->target, 'a');
    pa(a, b);
}

void prep_for_push (t_stack **stack , t_stack *top_node , char stack_name)
{
    while (*stack != top_node)
    {
        if (stack_name == 'a')
        {
            if(top_node->above_median)
                ra(stack);
            else
                rra(stack);
        }
        else if (stack_name == 'b')
        {
            if (top_node->above_median)
                rb(stack);
            else
                rrb(stack);
        }
    }
}

void init_nodes_b(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_b(a, b);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a; 
	t_stack	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX; 
		current_a = a;
		while (current_a)
		{
			if (current_a->data > b->data && current_a->data < best_match_index)
			{
				best_match_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_min_value(a);
		else
			b->target = target_node;
		b = b->next;
	}
}
void min_on_top (t_stack **a)
{
    t_stack *min;

    min = find_min_value(*a);
    while ((*a)->data != min->data)
    {
        if (min->above_median)
            ra(a);
        else
            rra(a);
    }
}

void sort_stack(t_stack **a, t_stack **b)
{
    int a_len;

    a_len = get_stack_size(*a);
    if (a_len-- > 3 && !stack_sorted(*a))
        pb(b, a);
    if (a_len-- > 3 && !stack_sorted(*a))
        pb(b, a);
    while (a_len > 3 && !stack_sorted(*a))
    {
        init_nodes_a(*a, *b);
        push_a_to_b(a, b);
        a_len--;
    }
    sort_three(a);
    while (*b)
    {
        init_nodes_b(*a, *b);
        push_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}
