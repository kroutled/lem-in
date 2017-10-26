#include "lemin.h"

void	ft_anthill(t_args *args, t_vars *vars)
{
	vars->count = 0;
	while (args->data[vars->count])
	{
						
		vars->count++;
	}
}

int main(int ac, char **av)
{
	int 	fd;
	t_args	args;
	t_vars	vars;

	ft_bzero(&args, sizeof(t_args));
	ft_bzero(&vars, sizeof(t_vars));
	if (ac != 2)
	{
		ft_putendl("Usage: ./lem-in [file]");
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		args.line = ft_readfile(fd);
		args.data = ft_strsplit(args.line, '\n');
		ft_anthill(&args, &vars);
	}
	return (0);	
}
