#include "libft.h"
#include "libtests.h"
#include "sort.h"
#include "parse.h"
#include <stdint.h>
#include <stdlib.h>

static void print_tab(const int *tab, size_t tab_len)
{
	size_t	i;

	i = 0;
	ft_printf("-------------------\n");
	while (i < tab_len)
		ft_printf("%d\n", tab[i++]);
	ft_printf("-------------------\n");
}


static void	print_stack(t_stack *stack)
{
	uint64_t	i;
	uint64_t	index;

	if (stack->top == 0)
		stack->top = stack->size;
	ft_printf("-------------------\n");
	i = 0;
	while (i < stack->len)
	{
		index = stack->bottom + i;
		if (index >= stack->size)
			index -= stack->size;
		ft_printf("%d\n", stack->content[index]);
		i++;
	}
	ft_printf("-------------------\n");
}

static int	*get_stack_copy(t_stack *stack)
{
	int			*copy;
	uint64_t	pos;
	uint64_t	i;
	
	copy = malloc(sizeof(int) * stack->len);
	if (copy == NULL)
		return (NULL);
	if (stack->top == 0)
		stack->top = stack->size;
	pos = stack->bottom;
	i = 0;
	while (pos != stack->top)
	{
		if (pos == stack->size)
			pos = 0;
		copy[i++] = stack->content[pos++];
	}
	return (copy);
}


int	test_sort(const char **args, size_t args_len,
		const int *sorted, size_t sorted_len, const char *test)
{
	int		errors;
	t_stack *stack_a;
	t_stack *stack_b;
	int		*stack_copy;
	
	ft_printf("Test\n");
	errors = 0;
	stack_a = init_stack(sorted_len);
	errors += expect_not_null(stack_a, "sort (stack_a initialization error)");
	stack_b = init_stack(sorted_len);
	errors += expect_not_null(stack_b, "sort (stack_b initialization error)");
	(void) parse_args(args, args_len, stack_a);
	sort(stack_a, stack_b);
	stack_copy = get_stack_copy(stack_a);
	errors += expect_not_null(stack_copy,
		"sort (stack_copy initialization error)");
	errors += expect_true(ft_memcmp(stack_copy, sorted,
			sizeof(int) * sorted_len) == 0, test);
	ft_printf("Expected stack:\n");
	print_tab(sorted, sorted_len);
	ft_printf("Got:\n");
	print_stack(stack_a);
	free(stack_copy);
	free_stack(stack_a);
	free_stack(stack_b);
	return (errors);
}

int	main(void)
{
	int	errors;

	errors = 0;
	errors += test_sort((const char *[]) {"4", "20", "15", "-2", "10"}, 5,
			(const int []){20, 15, 10, 4, -2}, 5,
			"sort (sorts random stack of numbers)");
	errors += test_sort((const char *[]) {"5", "4", "3", "2", "1"}, 5,
			(const int []){5, 4, 3, 2, 1}, 5,
			"sort (sorts stack sorted in descending order)");
	errors += test_sort((const char *[]) {"1", "2", "3", "4", "5"}, 5,
			(const int []){5, 4, 3, 2, 1}, 5,
			"sort (doesn't do anything for stack already sorted in ascending order)");
	errors += test_sort((const char *[]) {"1", "3", "2"}, 3,
			(const int []){3, 2, 1}, 3,
			"sort (sorts stack of size 3)");
	errors += test_sort((const char *[]) {"2", "1"}, 2,
			(const int []){2, 1}, 2,
			"sort (sorts stack of size 2)");
	if (errors == 0)
		ft_printf("\nsort: Success\n");
	return (0);
}
