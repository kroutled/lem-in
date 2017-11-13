#include "lemin.h"

void	ft_frees(t_args *args)
{
	if (args->line != NULL)
	{
		free(args->line);
		args->line = NULL;
	}
	if (args->args != NULL)
	{
		ft_free2d(args->args);
		args->args = NULL;
	}
	if (args->links != NULL)
	{
		ft_free2d(args->links);
		args->links = NULL;
	}
}

void    ft_free_ants()
{

}