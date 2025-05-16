
#include "lib_rt.h"

int	ft_print_str_fd(int fd, const char *s)
{
	int		count;

	count = 0;
	if (!s)
	{
		count += ft_print_str_fd(fd, "(null)");
	}
	else
	{
		if (!*s)
			return (0);
		while (s[count])
		{
			write(fd, &s[count], 1);
			count++;
		}
	}
	return (count);
}
