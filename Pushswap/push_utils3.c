#include "libft.h"
#include "push_swap.h"

void	sortthreeb(t_bucket **a)
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
	{
		sb(a, 1);
		rrb(a, 1);
		return ;
	}
	if (value1 > value2 && value1 > value3 && value2 > value3)
	{
		return ;
	}
	if (value1 > value2 && value1 < value3 && value2 < value3)
	{
		rrb(a, 1);
		return ;
	}
	if (value1 > value2 && value2 < value3 && value1 > value3)
	{
		sb(a, 1);
		rb(a, 1);
		return ;
	}
	if (value1 < value2 && value1 < value3 && value2 > value3)
	{
		rb(a, 1);
		return ;
	}
	if (value1 < value2 && value2 > value3 && value1 > value3)
	{
		sb(a, 1);
		return ;
	}
}

void	comparemax(t_bucket **a,t_bucket **b, t_max *max)
{
	t_bucket	*ptr;

	ptr = *a;
	if (ptr->content < max->v3)
	{
		if (ptr->content < getvaluefirst(b) && getvaluelast(b) < getvaluefirst(b))
		{
			if (ptr->content > getvaluelast(b) && ft_bucketsize(*b) > 2)
			{
				rrb(b, 1);
				pb(b, a);
			}
			else
			{
				pb(b, a);
				sb(b, 1);
			}
		}
		else
			pb(b, a);
	}
	else if (ptr->content >= max->v3)
		ra(a, 1);
}

void	reimplant(t_bucket **a, t_bucket **b)
{
	while (check(a, b) != 1)
	{
		optimize(get_max(b), b);
		pa(a, b);
	}
}

void	optimize(int	max, t_bucket	**b)
{
	t_bucket	*ptr;
	int	size;

	if (max == -2147483648)
		return ;
	ptr = *b;
	size = ft_bucketsize(ptr);
	if (findvalue(max, b) == 0)
		return ;
	if (findvalue(max, b) > (size / 2))
	{
		while (ptr->content != max)
		{
			rrb(b, 1);
			ptr = *b;
			if (!ptr || ptr->content == max)
				return ;
		}
	}
	if (findvalue(max, b) <= (size / 2))
	{
		while (ptr->content != max)
		{
			rb(b, 1);
			ptr = *b;
			if (!ptr || ptr->content == max)
				return ;
		}
	}
}

void	fillmax(t_max	*max, t_bucket	**a)
{
	t_bucket	*ptr;
	int	temp;
	int	temp2;
	int	loop;

	max->v1 = -2147483648;
	max->v2 = -2147483648;
	max->v3 = -2147483648;
	temp = 0;
	temp2 = 0;
	loop = 0;
	ptr = *a;
	while (loop != 3)
	{
		while (ptr)
		{
			if (ptr->content > max->v1)
			{
				temp = max->v1;
				max->v1 = ptr->content;
				temp2 = max->v2;
				max->v2 = temp;
				max->v3 = temp2;
			}
			else if (ptr->content > max->v2 && ptr->content < max->v1)
			{
				temp = max->v2;
				max->v2 = ptr->content;
				max->v3 = temp;
			}
			else if (ptr->content > max->v3 && ptr->content < max->v2)
				max->v3 = ptr->content;
			ptr = ptr->next;
		}
		ptr = *a;
		loop++;
	}
}
