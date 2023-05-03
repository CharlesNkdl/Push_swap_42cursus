#include "libft.h"
#include "push_swap.h"

void ft_error(void)
{
    ft_putendl_fd("Error",2);
    exit (2);
}

void	ft_error_split(char **argv)
{
	ft_putendl_fd("Error",2);
	ft_freesplit(argv, ft_sizing(argv));
    exit (2);
}

void ft_check(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < argc - 1)
    {
        if (argv[i][0] == '-')
        {
            j++;
            if (!argv[i][1] || ft_isdigit((int)argv[i][j]) == 0)
                ft_error_split(argv);
        }
        else if (ft_isdigit((int)argv[i][j]) == 0)
            ft_error_split(argv);
        while (argv[i][j] && ft_isdigit((int)argv[i][j]) != 0)
        {
            j++;
            if (argv[i][j] && ft_isdigit((int)argv[i][j]) == 0)
                ft_error_split(argv);
        }
        if (((ft_atoi(argv[i])) < -2147483648) || (ft_atoi(argv[i]) > 2147483647) || (ft_strlen(argv[i]) > 14))
            ft_error_split(argv);
        i++;
        j = 0;
    }
}

int *ft_checkdoubl(int argc, char **argv)
{
    int *grid;
    int i;
    int j;

    grid = malloc((argc + 1) * sizeof(int));
    if (!grid)
        return (NULL);
    i = 0;
    j = 0;
    while (argv[i])
    {
        grid[i] = atoi(argv[i]);
        i++;
    }
    i = 0;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (grid[i] == grid[j])
            {
                free (grid);
                ft_error_split(argv);
            }
            j++;
        }
        i++;
    }
    return (grid);
}
