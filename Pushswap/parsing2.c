#include "libft.h"
#include "push_swap.h"

int	*sort_stack(int *stack, int argc)
{
	int	*grid;
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	grid =  malloc((argc + 1) * sizeof(int));
	if (!grid)
		return (NULL);
	while (i != argc)
	{
		grid[i] = stack[i];
		i++;
	}
	i = 0;
	while (i != argc)
	{
		j = i + 1;
		while (j != argc)
		{
			if (grid[i] > grid[j])
			{
				temp = grid[i];
				grid[i] = grid[j];
				grid[j] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i != argc)
	{
		j = 0;
		while (stack[i] != grid[j])
			j++;
		stack[i] = j;
		i++;
	}
	free(grid);
	return (stack);
}
