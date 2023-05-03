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

void    ft_miracle(int *stack, int argc)
{
    t_bucket  *a;
    t_bucket  *b;
    int i;

    i = 0;
	a = NULL;
	b = NULL;
    while (i != argc)
    {
        ft_bucketadd_back(&a, ft_bucketnew(stack[i]));
        i++;
    }
    free (stack);
	if (check(&a,&b) == 1)
		i += 1;
	else if (argc == 2)
	{
		if (check(&a,&b) != 1)
			ra(&a, 1);
	}
	else if (argc == 3)
		sortthreea(&a);
	else if (argc <= 8)
		algo(&a,&b);
	else
		vivalgo(&a, &b);
	free_bucket(&a);
	free_bucket(&b);
	return ;
}

int main(int argc, char *argv[])
{
    int *stack;
	char	**splitted;
	char *keeper;
	int	i;

    if (argc < 2)
		return (0);
	i = 1;
	keeper = NULL;
	while (i < argc)
	{
		keeper = ft_strjoin(keeper, argv[i]);
		i++;
	}
	splitted = ft_split(keeper,' ');
	free(keeper);
    ft_check(argc, splitted);
    stack = ft_checkdoubl(ft_sizing(splitted), splitted);
	stack = sort_stack(stack, ft_sizing(splitted));
    ft_miracle(stack, ft_sizing(splitted));
	ft_freesplit(splitted, ft_sizing(splitted) + 1);
    return (0);
}

void	**ft_freesplit(char **tabl, int i)
{
	int	j;

	j = 0;
	while (j < i && tabl[j])
	{
		free(tabl[j]);
		j++;
	}
	free(tabl);
	return (0);
}
