#include "libft.h"
#include "push_swap.h"

int    sa(t_bucket **a, int version)
{
    t_bucket    *temp;

    if (*a == NULL || (*a)->next == NULL)
        return (0);
    temp = (*a)->next;
    (*a)->next = temp->next;
    temp->next = (*a);
    (*a) = temp;
	if (version == 1)
		ft_putendl_fd("sa", 1);
	return (1);
}

int    sb(t_bucket **a, int version)
{
    t_bucket    *temp;

    if (*a == NULL || (*a)->next == NULL)
        return (0);
    temp = (*a)->next;
    (*a)->next = temp->next;
    temp->next = (*a);
    (*a) = temp;
	if (version == 1)
		ft_putendl_fd("sb", 1);
	return (1);
}

void    ss(t_bucket **a, t_bucket **b)
{
	if ((sa(a, 0) == 1) || (sb(b, 0) == 1))
		ft_putendl_fd("ss", 1);
}

int    pa(t_bucket **a,t_bucket **b)
{
	t_bucket *tmp;
	t_bucket *origin;
	t_bucket *destination;

	if (!(*b))
		return (0);
	destination = *a;
	origin = *b;
	tmp = origin;
	origin = origin->next;
	*b = origin;
	if (!destination)
	{
		destination = tmp;
		destination->next = NULL;
		*a = destination;
	}
	else
	{
		tmp->next = destination;
		*a = tmp;
	}
	ft_putendl_fd("pa", 1);
	return (1);
}

int    pb(t_bucket **a,t_bucket **b)
{
	t_bucket *tmp;
	t_bucket *origin;
	t_bucket *destination;

	if (!(*b))
		return (0);
	destination = *a;
	origin = *b;
	tmp = origin;
	origin = origin->next;
	*b = origin;
	if (!destination)
	{
		destination = tmp;
		destination->next = NULL;
		*a = destination;
	}
	else
	{
		tmp->next = destination;
		*a = tmp;
	}
	ft_putendl_fd("pb", 1);
	return (1);
}

int    ra(t_bucket **a, int version)
{
    t_bucket    *temp;

    temp = ft_bucketlast(*a);
    if (temp == NULL || temp == *a)
        return (0);
    temp->next = *a;
    temp = temp->next;
    *a = (*a)->next;
    temp->next = NULL;
	if (version == 1)
		ft_putendl_fd("ra", 1);
	return (1);
}

int    rb(t_bucket **a, int version)
{
    t_bucket    *temp;

    temp = ft_bucketlast(*a);
    if (temp == NULL || temp == *a)
        return (0);
    temp->next = *a;
    temp = temp->next;
    *a = (*a)->next;
    temp->next = NULL;
	if (version == 1)
		ft_putendl_fd("rb", 1);
	return (1);
}

void    rr(t_bucket **a, t_bucket **b)
{
	if ((ra(a, 0) == 1) || (rb(b, 0) == 1))
		ft_putendl_fd("rr", 1);
}

int    rra(t_bucket **a,int version)
{
    t_bucket    *temp;
    t_bucket    *pointer;
    t_bucket    *first;
    int value;

    temp = *a;
    temp = ft_bucketlast(temp);
    if (temp == NULL || temp == *a)
        return (0);
    pointer = ft_bucketbeflast(*a);
    value = temp->content;
    free(temp);
    pointer->next = NULL;
    first = ft_bucketnew(value);
    first->next = *a;
    *a = first;
	if (version == 1)
		ft_putendl_fd("rra", 1);
	return (1);

}

int    rrb(t_bucket **a, int version)
{
    t_bucket    *temp;
    t_bucket    *pointer;
    t_bucket    *first;
    int value;

    temp = *a;
    temp = ft_bucketlast(temp);
    if (temp == NULL || temp == *a)
        return (0);
    pointer = ft_bucketbeflast(*a);
    value = temp->content;
    free(temp);
    pointer->next = NULL;
    first = ft_bucketnew(value);
    first->next = *a;
    *a = first;
	if (version == 1)
		ft_putendl_fd("rrb", 1);
	return (1);
}

void    rrr(t_bucket **a,t_bucket **b)
{
	if ((rra(a, 0) == 1) || (rrb(b, 0) == 1))
		ft_putendl_fd("rrr", 1);
}
