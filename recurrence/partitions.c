#include <stdio.h>
#include <limits.h>
#include "partitions.h"

int	obtain_partition(unsigned long long *previous, int n, int size)
{
	int	k;
	int	sign;
	int	to_subtract;

	if (n >= size)
	{
		ft_realloc(
				(void **) &previous,
				size * sizeof(unsigned long long),
				sizeof(unsigned long long) * (size * 2));
		size = size * 2;
	}
	k = 1;
	to_subtract = k * (3 * k - 1) / 2;
	sign = k % 2 == 0 ? -1 : 1;
	previous[n] = 0;
	while (to_subtract <= n)
	{
		previous[n] += sign * previous[n - to_subtract];
		k = k >= 0 ? -k : -k + 1;
		sign = k % 2 == 0 ? -1 : 1;
		to_subtract = k * (3 * k - 1) / 2;
	}
	if (previous[n] == 1000000)
		return (n);
	return (obtain_partition(previous, n + 1, size));
}

int	main(void)
{
	unsigned long long	*first;

	first = ft_alloc(sizeof(unsigned long long) * 128);
	first[0] = 1;
	printf("\n%d\n", obtain_partition(first, 1, 128));
}
