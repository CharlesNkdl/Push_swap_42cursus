#include "libft.h"
#include "push_swap.h"

void	algo(t_bucket **a, t_bucket **b)
{
	t_bucket	*ptr;
	t_max	maxa;

	fillmax(&maxa, a);
	ptr = *a;
	if (check(a,b) == 1)
		return ;
	while (ft_bucketsize(ptr) > 3)
	{
		comparemax(a, b, &maxa);
		ptr = *a;
	}
	sortthreea(a);
	reimplant(a, b);
	return ;
}
