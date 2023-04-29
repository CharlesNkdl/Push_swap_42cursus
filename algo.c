#include "libft.h"
#include "push_swap.h"

void	algo(t_bucket **a, t_bucket **b)
{
	t_bucket	*ptr;
	t_max	maxa;

	fillmax(&maxa, a);
	//printf("%d", maxa.v1);
	//printf("%d", maxa.v2);
	//printf("%d", maxa.v3);
	ptr = *a;
	if (check(a,b) == 1)
		return ;
	while (ft_bucketsize(ptr) > 3)
	{
		comparemax(a, b, &maxa);
		/*if (ptr)
		pa(b, a);*/
		ptr = *a;
	}
	sortthreea(a);
	reimplant(a, b);
	return ;
}

void	sortthreea(t_bucket **a)
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
		return ;
	if (value1 > value2 && value1 > value3 && value2 > value3)
	{
		sa(a, 1);
		rra(a, 1);
		return ;
	}
	if (value1 > value2 && value1 < value3 && value2 < value3)
	{
		sa(a, 1);
		return ;
	}
	if (value1 > value2 && value2 < value3 && value1 > value3)
	{
		ra(a,1);
		return ;
	}
	if (value1 < value2 && value1 < value3 && value2 > value3)
	{
		sa(a, 1);
		ra(a, 1);
		return ;
	}
	if (value1 < value2 && value2 > value3 && value1 > value3)
	{
		rra(a, 1);
		return ;
	}
}

void	reimplant(t_bucket **a, t_bucket **b)
{
	while (check(a, b) != 1)
	{
		optimize(get_max(b), b);
		pb(a, b);
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

void	comparemax(t_bucket **a,t_bucket **b, t_max *max)
{
	t_bucket	*ptr;

	ptr = *a;
	if (ptr->content < max->v3)
	{
		pa(b, a);
		return ;
	}
	else if (ptr->content >= max->v3)
	{
		ra(a, 1);
		return ;
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
			if (!ptr)
				return ;
			if (ptr->content == max)
				return ;
		}
	}
	if (findvalue(max, b) <= (size / 2))
	{
		while (ptr->content != max)
		{
			rb(b, 1);
			ptr = *b;
			if (!ptr)
				return ;
			if (ptr->content == max)
				return ;
		}
	}
}

int	get_max(t_bucket **b)
{
	t_bucket	*ptr;
	int	find;

	ptr = *b;
	find = getvaluefirst(b);
	while (ptr)
	{
		ptr = ptr->next;
		if (!ptr)
			return (find);
		if (ptr->content > find)
			find = ptr->content;
	}
	return (find);
}
