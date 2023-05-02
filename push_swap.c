#include "libft.h"
#include "push_swap.h"

void print_stack(t_bucket *stack)
{
    t_bucket *current = stack;

    while (current != NULL)
    {
        printf("%d ", current->content);
        current = current->next;
    }
    printf("\n");
}

int	*sort_stack(int *stack, int argc)
{
	int	*grid;
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	grid =  malloc((argc - 1) * sizeof(int));
	if (!grid)
		return (NULL);
	while (i < argc)
	{
		grid[i] = stack[i];
		i++;
	}
	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
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
	while (i < argc)
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

int	check(t_bucket **a, t_bucket **b)
{
	t_bucket	*ptr;
	int	temp;

	if (*b)
		return (0);
	ptr = *a;
	while (ptr->next)
	{
		temp = ptr-> content;
		ptr = ptr->next;
		if (temp > ptr->content)
			return (0);
	}
	return (1);
}

void    ft_miracle(int *stack, int argc)
{
    t_bucket  *a;
    t_bucket  *b;
    int i;

    i = 0;
	a = NULL;
	b = NULL;
    while (i < argc - 1)
    {
        ft_bucketadd_back(&a, ft_bucketnew(stack[i]));
        i++;
    }
    free (stack);
	if (argc == 3)
	{
		if (check(&a,&b) != 1)
		{
			ra(&a, 1);
			exit(0);
		}
		if (check(&a,&b) == 1)
			exit(0);
	}
	//if (argc < 9)
	//algolil(&a,&b);
	vivalgo(&a, &b);
	//else
		//god_plan(&a, &b);
	printf(" Stack B : ");
    print_stack(b);
	printf(" Stack A : ");
    print_stack(a);
	printf("size A : %d \n", ft_bucketsize(a));
	printf("size B : %d \n", ft_bucketsize(b));
	if (check(&a,&b) == 1)
		ft_putendl_fd("ok", 1);
}

int main(int argc, char *argv[])
{
    int *stack;

    if (argc < 2)
        return (0);
    //Check si il n'ya que des chiffres et qu'ils tiennent dans un int
    ft_check(argc, argv);
    // check si y a des doublons puis les mets dans un tableau avec atoi
    stack = ft_checkdoubl(argc, argv);
	stack = sort_stack(stack, argc);
    ft_miracle(stack, argc);

    return (1);

}
