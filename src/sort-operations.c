#include "sort.h"

t_operations	find_minimum_operations(uint64_t index,
		t_stack *src_stack, t_stack *dest_stack, bool asc)
{
	t_operations	min_ops;
	uint64_t		target;

	min_ops.src_stack_ops = gap_to_top(src_stack, index, true);
	if (asc)
		target = find_minimum_bigger(dest_stack, src_stack->content[index]);
	else
		target = find_maximum_smaller(dest_stack, src_stack->content[index]);
	min_ops.dest_stack_ops = gap_to_top(dest_stack, target, true);
	if ((min_ops.src_stack_ops < 0 && min_ops.dest_stack_ops < 0)
		|| (min_ops.src_stack_ops > 0 && min_ops.dest_stack_ops > 0))
		min_ops.sum = min_ops.src_stack_ops - min_ops.dest_stack_ops;
	else if (min_ops.src_stack_ops < 0)
		min_ops.sum = min_ops.src_stack_ops - min_ops.dest_stack_ops;
	else
		min_ops.sum = min_ops.dest_stack_ops - min_ops.src_stack_ops;
	if (min_ops.sum < 0)
		min_ops.sum = -min_ops.sum;
	min_ops.sum++;
	return (min_ops);
}

t_operations	find_best_operations(t_stack *src_stack,
		t_stack *dest_stack, bool asc)
{
	t_operations	best_ops;
	t_operations	ops;
	uint64_t		i;

	i = src_stack->bottom;
	if (src_stack->top == 0)
		src_stack->top = src_stack->size;
	best_ops.sum = src_stack->size + dest_stack->size;
	while (i != src_stack->top)
	{
		if (i == src_stack->size)
			i = 0;
		ops = find_minimum_operations(i, src_stack, dest_stack, asc);
		if (ops.sum < best_ops.sum)
			best_ops = ops;
		i++;
	}
	return (best_ops);
}
