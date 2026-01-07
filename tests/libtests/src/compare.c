#include "libtests.h"


int	expect_eq_int(int i, int expected, const char *test)
{
	if (i != expected)
	{
		printf("\n%s: expected \"%d\", got \"%d\"\n",
			test, expected, i);
		return (1);
	}
	return (0);
}

int	expect_eq_str(const char *str, const char *expected, const char *test)
{
	if (strcmp(str, expected) != 0)
	{
		printf("\n%s: expected \"%s\", got \"%s\"\n",
			test, expected, str);
		return (1);
	}
	return (0);
}

int		expect_eq_ptr(void *ptr, void *expected, const char *test)
{
	if (ptr != expected)
	{
		printf("\n%s: expected \"%p\", got \"%p\"\n",
			test, expected, ptr);
		return (1);
	}
	return (0);
}

int	expect_null(void *ptr, const char *test)
{
	if (ptr != NULL)
	{
		printf("\n%s: expected pointer to be NULL\n", test);
		return (1);
	}
	return (0);
}

int		expect_not_null(void *ptr, const char *test)
{
	if (ptr == NULL)
	{
		printf("\n%s: expected pointer not to be NULL\n", test);
		return (1);
	}
	return (0);
}

int		expect_true(int condition, const char *test)
{
	return (expect_eq_int(condition, 1, test));
}

int		expect_false(int condition, const char *test)
{
	return (expect_eq_int(condition, 0, test));
}
