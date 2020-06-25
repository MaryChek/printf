#include "libft.h"

size_t		ft_base_intlen(ULL_int n, int base)
{
	size_t	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}