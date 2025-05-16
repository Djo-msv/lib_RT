
#include "lib_rt.h"

int	ft_print_integer_fd(int fd, int n)
{
	char	*s;
	int		count;

	s = ft_itoa(n);
	count = ft_print_str_fd(fd, s);
	free(s);
	return (count);
}
