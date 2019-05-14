#ifndef PARTITIONS_H
# define PARTITIONS_H

# include "libft.h"

int		get_partition_size(int *partition);
int		*expand_partition(int *partition, int *amount_expanded);
void	print_partition(int *partition);

#endif
