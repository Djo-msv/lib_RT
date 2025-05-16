
#include "lib_rt.h"

int	ft_print_char_fd(int fd, int n)
{
	unsigned char	c;

	c = (unsigned char) n ;
	write(fd, &c, 1);
	return (1);
}
