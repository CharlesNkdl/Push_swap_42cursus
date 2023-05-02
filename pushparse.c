#include "libft.h"
#include "push_swap.h"

void ft_error(void)
{
    ft_putendl_fd("ERROR",1);
    exit (0);
}

void ft_check(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < argc)
    {
        if (argv[i][0] == '-')
        {
            j++;
            if (!argv[i][1] || ft_isdigit((int)argv[i][j]) == 0)
                ft_error();
        }
        else if (ft_isdigit((int)argv[i][j]) == 0)
            ft_error();
        while (argv[i][j] && ft_isdigit((int)argv[i][j]) != 0)
        {
            j++;
            if (argv[i][j] && ft_isdigit((int)argv[i][j]) == 0)
                ft_error();
        }
        if (((ft_atoi(argv[i])) < -2147483648) || (ft_atoi(argv[i]) > 2147483647) || (ft_strlen(argv[i]) > 14))
            ft_error();
        i++;
        j = 0;
    }
}

int *ft_checkdoubl(int argc, char **argv)
{
    int *grid;
    int i;
    int j;

    grid = malloc((argc - 1) * sizeof(int));
    if (!grid)
        return (NULL);
    i = 1;
    j = 0;
    while (i <= argc - 1)
    {
        grid[i-1] = atoi(argv[i]);
        //printf("index : %d , %d \n", i, grid[i-1]);
        i++;
    }
    i = 0;
    while (i < argc - 1)
    {
        j = i + 1;
        while (j < argc - 1)
        {
            if (grid[i] == grid[j])
            {
                free (grid);
                ft_error();
            }
            j++;
        }
        i++;
    }
    return (grid);
}
