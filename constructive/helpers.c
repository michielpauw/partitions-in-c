#include "partitions.h"
#include <stdio.h>

int	get_partition_size(int *partition)
{
	int	size;

	size = 0;
	while (*(partition + size))
		size++;
	return (size);
}

int	*expand_partition(int *partition, int *amount_expanded)
{
	int	*expanded;

	if (partition[1] != 0 && partition[0] >= partition[1])
		return (NULL);
	(*amount_expanded)++;
	expanded = ft_alloc(sizeof(int) * 3);
	expanded[0] = partition[0] + 1;
	expanded[1] = partition[1];
	expanded[2] = 0;
	return (expanded);
}

void	print_partition(int *partition)
{
	int	i;

	i = 0;
	while (i < 3)
		printf("%d ", partition[i++]);
	printf("\n");
}

void	free_partitions(int **partitions, int length)
{
	int	i;

	if (length == 0)
		return ;
	i = 0;
	while (i < length)
		free(partitions[i++]);
	free(partitions);
}
