#include "libft.h"
#include "push_swap.h"

void	algolil(t_bucket **a, t_bucket **b)
{
	int	size;

	while (size != 1)
	{
		size = ft_bucketsize(*a);
		if (nextbest(get_max(a), get_min(a), size, a) == 2)
		{
			if (rr_ou_r(get_max(a), a) == 1)
			{
				while (get_max(a) != getvaluefirst(a))
					rra(a , 1);
				pa(b, a);
				if (getvaluefirst(b) == get_min(b) + 1)
					rb(b, 1);
			}
			else if (rr_ou_r(get_max(a), a) == 2)
			{
				while (get_max(a) != getvaluefirst(a))
					ra(a, 1);
				pa(b, a);
				if (getvaluefirst(b) == get_min(b) + 1)
					rb(b, 1);
			}
		}
		else if (nextbest(get_max(a), get_min(a), size, a) == 1)
		{
			if (rr_ou_r(get_min(a), a) == 1)
			{
				while (get_min(a) != getvaluefirst(a))
					rra(a , 1);
				pa(b, a);
				if (getvaluefirst(b) == get_min(b) + 1)
					rb(b, 1);
			}
			else if (rr_ou_r(get_min(a), a) == 2)
			{
				while (get_min(a) != getvaluefirst(a))
					ra(a, 1);
				pa(b, a);
				if (getvaluefirst(b) == get_min(b) + 1)
					rb(b, 1);
			}
		}
	}
}

int	nextbest(int max, int min, int size, t_bucket **a)
{
	int	maxins;
	int	minins;

	minins = 0;
	maxins = 0;
	minins += findvalue(min, a);
	//printf("%d\n", minins);
	if (minins > size/2)
		minins = size - minins;
	maxins += findvalue(max, a);
	//printf("%d\n", maxins);
	if (maxins > size/2)
		maxins = size - maxins;
	minins ++;
	//printf("%d\n", minins);
	//printf("%d\n", maxins);
	if (minins < maxins)
		return (1);
	if (maxins <= minins)
		return (2);
	return (0);
}

int	rr_ou_r(int	nbr, t_bucket **a)
{
	if (findvalue(nbr, a) >= ft_bucketsize(*a) / 2)
		return (2);
	else if (findvalue(nbr, a) <= ft_bucketsize(*a) / 2)
		return (1);
	return (0);
}
