#include "libft.h"
#include "libtests.h"
#include "parse.h"

int	test_valid_args(const char **args, size_t args_size,
		int *expected_stack, size_t expected_size, const char *test)
{
	int		errors;
	t_stack	*stack;

	errors = 0;
	errors += expect_eq_int(parse_args(args, args_size, NULL), expected_size,
		"parse_args (returns expected size)");
	stack = init_stack(expected_size);
	(void) parse_args(args, args_size, stack);
	errors += expect_true(ft_memcmp(stack->content, expected_stack, sizeof(int) * expected_size) == 0,
		"parse_args (fills stack as expected)");
	errors += expect_eq_int(stack->top, stack->size,
		"parse_args(sets stack top to the size of the stack)");
	errors += expect_eq_int(stack->bottom, 0,
		"parse_args(sets stack bottom to 0)");
	free_stack(stack);
	expect_true(errors == 0, test);
	return (errors);
}

int	test_invalid_args(const char **args, size_t args_size,
		bool fail_on_first_call, const char *test)
{
	int		errors;
	t_stack	*stack;
	size_t	size;

	errors = 0;
	if (fail_on_first_call)
		errors += expect_eq_int(parse_args(args, args_size, NULL), 0, test);
	else
	{
		size = parse_args(args, args_size, NULL);
		errors += expect_false(size == 0,
			"parse_args (works on first call for invalid args)");
		stack = init_stack(size);
		errors += expect_eq_int(parse_args(args, args_size, stack), 0,
			"parse_args (fails on second call for invalid args)");
		free_stack(stack);
		expect_true(errors == 0, test);
	}
	return (errors);
}

int	main(void)
{
	int	errors;

	errors = 0;
	errors += test_valid_args((const char *[]){"1", "2", "3", "4", "5"}, 5,
			(int[]){5, 4, 3, 2, 1}, 5,
			"parse_args (works for multiple args with single numbers)");
	errors += test_valid_args((const char *[]){"1 2 3 4 5"}, 1,
			(int[]){5, 4, 3, 2, 1}, 5,
			"parse_args (works for single arg with multiple numbers)");
	errors += test_valid_args((const char *[]){"1", "2", "3 4", "5"}, 4,
			(int[]){5, 4, 3, 2, 1}, 5,
			"parse_args (works for mixed args)");
	errors += test_valid_args((const char *[]){"-10", "-0", "0"}, 3,
			(int[]){0, 0, -10}, 3,
			"parse_args (works for negative numbers)");
	errors += test_valid_args((const char *[]){"+10"}, 1,
			(int[]){10}, 1,
			"parse_args (works for positive numbers with a +)");
	errors += test_invalid_args((const char *[]){"1", "two", "3"}, 3, true,
			"parse_args (refuse non-number arguments)");
	errors += test_invalid_args((const char *[]){"2147483648"}, 1, true,
			"parse_args (refuse overflowing numbers)");
	errors += test_invalid_args((const char *[]){"-2147483649"}, 1, true,
			"parse_args (refuse underflowing numbers)");
	errors += test_invalid_args((const char *[]){"1 2 3 3 4 5"}, 1, false,
			"parse_args (refuse duplicates)");
	if (errors == 0)
		ft_printf("\nparse_args: Success\n");
	return (0);
}
