#include "partitions.h"
#include <stdio.h>

static int	**get_new_entries(int **partition, int *amount_expanded)
{
	int	**new_partition;

	new_partition = ft_alloc(2 * sizeof(int *));
	new_partition[0] = ft_alloc(3 * sizeof(int));
	new_partition[0][0] = 1;
	new_partition[0][1] = (*partition)[0];
	new_partition[0][2] = 0;
	*amount_expanded = 1;
	new_partition[1] = expand_partition(*partition, amount_expanded);
	free(*partition);
	return (new_partition);
}

static int	get_partition_number(int **previous, int count, int length)
{
	int	i;
	int	j;
	int	allocated;
	int	amount_expanded;
	int	**new;
	int	**expanded;

	amount_expanded = 0;
	if (length % 21 == 0)
		return (count);
	i = 0;
	j = 0;
	allocated = length;
	new = ft_alloc(sizeof(int *) * allocated);
	while (i < length) 
	{
		if (j + amount_expanded >= allocated)
		{
			ft_realloc((void **) &new, sizeof(int *) * allocated, sizeof(int *) * allocated * 2);
			allocated = allocated * 2;
		}
		expanded = get_new_entries(&(previous[i]), &amount_expanded);
		i++;
		new[j++] = expanded[0];
		if (amount_expanded == 2)
			new[j++] = expanded[1];
	}
	i = 0;
	printf("%d\n", j);
	free(previous);
	return (get_partition_number(new, count + 1, j));
}

int			main(void)
{
	int	**first;
	int	*entry;

	entry = ft_alloc(sizeof(int) * 3);
	entry[0] = 1;
	entry[1] = 0;
	entry[2] = 0;
	first = ft_alloc(sizeof(int *));
	first[0] = entry;
	printf("%d\n", get_partition_number(first, 1, 1));
}
