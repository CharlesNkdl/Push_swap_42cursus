#include "libft.h"
#include "push_swap.h"

void	vivalgo(t_bucket **a, t_bucket **b)
{
	int	size;
	int	denom;
	int	i;

	i = 1;
	size = ft_bucketsize(*a);
	denom = ft_denom(size);
	chunk(a, b, -1, size/denom);
	while (i != denom - 1)
	{
		chunk(a, b, (size/denom) * i, (size/denom) * (i+1));
		i++;
		if (i == denom - 1)
			chunk(a, b, (size/denom) * i, size);
	}
	repush(a,b);
	return ;
}

void	repush(t_bucket **a, t_bucket **b)
{
	while ((*b))
	{
		while (getvaluefirst(b) != get_max(b))
		{
			if (findvalue(get_max(b),b) == 1)
				sb(b, 1);
			else if (findvalue(get_max(b), b) > ft_bucketsize(*b) / 2)
				rrb(b, 1);
			else
				rb(b,1);
		}
		pa(a, b);
	}
	return ;
}

void	chunk(t_bucket **a, t_bucket **b, int min, int max)
{
	int	good;
	t_ins	ins;

	initializeins(&ins);
	good = 0;
	while (good != max - min && ft_bucketsize(*a) != 0)
	{
		ins = optimal(a, min, max);
		while (inicount(ins) != 0)
		{
			if (ins.ra != 0)
			{
				ra(a, 1);
				ins.ra--;
			}
			else if (ins.rra != 0)
			{
				rra(a, 1);
				ins.rra--;
			}
		}
		pb(b, a);
		good++;
	}
}

t_ins	optimal(t_bucket **a, int min, int max)
{
	t_ins	stock;
	t_ins	best;
	t_bucket	*ptr;
	int	count;
	int	size;
	int	temp;

	size = ft_bucketsize(*a);
	initializeins(&stock);
	initializeinsneg(&best);
	temp = 999999;
	ptr = *a;
	count = 0;
	while (ptr)
	{
		if (ptr->content >= min && ptr->content <= max)
		{
			if (temp > inicount(stock))
			{
				stock.copy = ptr->content;
				temp = inicount(stock);
				inicpy(&stock, &best);
			}
		}
		ptr = ptr->next;
		if (count >= size / 2)
		{
			stock.ra = 0;
			stock.rra = size - count - 1;
		}
		else
			stock.ra++;
		count++;
	}
	return (best);
}

int	ft_denom(int size)
{
	if (size < 50)
		return (5);
	else if (size <= 100)
		return (7);
	else if (size <= 150)
		return (8);
	else if (size <= 250)
		return (9);
	else if (size <= 350)
		return (10);
	else if (size <= 400)
		return (11);
	else
		return (13);
}
