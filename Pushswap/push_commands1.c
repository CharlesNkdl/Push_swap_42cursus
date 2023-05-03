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
