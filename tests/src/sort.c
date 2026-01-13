#include "libft.h"
#include "libtests.h"
#include "sort.h"
#include "parse.h"


int	test_sort(const char **args, size_t args_len,
		const int *sorted, size_t sorted_len, const char *test)
{
	int		errors;
	t_stack *stack_a;
	t_stack *stack_b;
	
	errors = 0;
	stack_a = init_stack(sorted_len);
	errors += expect_not_null(stack_a, "sort (stack_a initialization error)");
	stack_b = init_stack(sorted_len);
	errors += expect_not_null(stack_b, "sort (stack_b initialization error)");
	(void) parse_args(args, args_len, stack_a);
	sort(stack_a, stack_b);
	errors += expect_true(ft_memcmp(stack_a->content, sorted,
			sizeof(int) * sorted_len) == 0, test);
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
