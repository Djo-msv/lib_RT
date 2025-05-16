
#include "lib_rt.h"

int	ft_print_address_fd(int fd, intptr_t address)
{
	int		count;

	count = 0;
	if (address == 0)
	{
		count += ft_print_str_fd(fd, "(nil)");
	}
	else
	{
		count = ft_print_str_fd(fd, "0x");
		count += ft_print_hexa_fd(fd, address, 0);
	}
	return (count);
}
