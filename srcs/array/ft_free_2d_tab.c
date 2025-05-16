
#include "lib_rt.h"

void	ft_free_2d_tab(char **tab)
{
	int i;
	
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
