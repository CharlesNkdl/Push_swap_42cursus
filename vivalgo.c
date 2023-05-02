#include "libft.h"
#include "push_swap.h"

void	vivalgo(t_bucket **a, t_bucket **b)
{
	int	size;
	int	denom;

	size = ft_bucketsize(*a);
	denom = 10;
	//while (check(a, b) != 1)
	chunk(a, b, -1, size/denom);
	chunk(a, b, size/denom, (size/denom) * 2);
	chunk(a, b, (size/denom) * 2, (size/denom) * 3);
	chunk(a, b, (size/denom) * 3, (size/denom) * 4);
	chunk(a, b, (size/denom) * 4, (size/denom) * 5);
	chunk(a, b, (size/denom) * 5, (size/denom) * 7);
	chunk(a, b, (size/denom) * 7, (size/denom) * 9);
	//chunk(a, b, (size/denom) * 7, (size/denom) * 8);
	//chunk(a, b, (size/denom) * 8, (size/denom) * 9);
	chunk(a, b, (size/denom) * 9, size);
	repush(a,b);
	return ;
}

void	repush(t_bucket **a, t_bucket **b)
{
	while (ft_bucketsize(*b) != 0)
	{
		while (getvaluefirst(b) != get_max(b))
		{
			if (findvalue(get_max(b), b) > ft_bucketsize(*b) / 2)
				rrb(b, 1);
			else
				rb(b,1);
		}
		pb(a, b);
	}
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
		//if (ft_bucketsize(*b) > 3)
			//optimalb(b, &ins, min);
		if ((ft_bucketsize(*b) == 3))
			sortthreeb(b);
		while (inicount(ins) != 0)
		{
			/*if (ins.rb != 0 && ins.ra != 0)
			{
				rr(a, b);
				ins.ra--;
				ins.rb--;
			}*/
			if (ins.ra != 0)
			{
				ra(a, 1);
				ins.ra--;
			}
			/*else if (ins.rb != 0)
			{
				rb(b, 1);
				ins.rb--;
			}*/
			else if (ins.rra != 0)
			{
				rra(a, 1);
				ins.rra--;
			}
		}
		pa(b, a);
		good++;
	}
}

int	next_three(t_bucket **a)
{
	t_bucket *ptr;
	int	value1;
	int	value2;
	int value3;

	ptr = *a;
	value1 = ptr->content;
	ptr = ptr->next;
	value2 = ptr->content;
	ptr = ptr->next;
	value3 = ptr->content;
	if (value1 < value2 && value1 < value3 && value2 < value3)
		return (1);
	else
		return (0);
}

int	next_threesum(t_bucket **a)
{
	t_bucket *ptr;
	int	value1;
	int	value2;
	int value3;

	ptr = *a;
	value1 = ptr->content;
	ptr = ptr->next;
	value2 = ptr->content;
	ptr = ptr->next;
	value3 = ptr->content;
	return (value1 + value2 + value3);
}

int	sortedb(t_bucket **a)
{
	t_bucket	*ptr;
	int	temp;

	ptr = *a;
	while (ptr->next)
	{
		temp = ptr-> content;
		ptr = ptr->next;
		if (temp < ptr->content)
			return (0);
	}
	return (1);
}

t_ins	optimal(t_bucket **a, int min, int max)
{
	t_ins	stock;
	t_ins	best;
	t_bucket	*ptr;
	int	count;
	int	size;
	int	temp;

	//printf(" min %d max %d \n", min, max);
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
			//printf("RRA %d \n", stock.rra);
			if (temp > inicount(stock))
			{
				stock.copy = ptr->content;
				temp = inicount(stock);
				inicpy(&stock, &best);
				//return (best);
			}
		}
		ptr = ptr->next;
		//printf(" BUCKETSIZE %d SIZE %d \n", ft_bucketsize(ptr), size);
		if (count >= size / 2)
		{
			stock.ra = 0;
			stock.rra = size - count - 1;
			//printf("RRA %d \n", stock.rra);
		}
		else
			stock.ra++;
		count++;
	}
	//printf(" RA %d RRA %d \n", best.ra, best.rra);
	return (best);
}

/*void	optimalb(t_bucket **b, t_ins	*ins, int min)
{
	int	sizeb;
	t_bucket *ptr;

	ptr = *b;
	if (ins->copy > get_max(b))
	{
		while (ptr->


	}
}*/
