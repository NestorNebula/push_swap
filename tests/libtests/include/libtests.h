#ifndef TESTS_H

#define TESTS_H

#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		expect_eq_int(int i, int expected, const char *test);

int		expect_eq_str(const char *str, const char *expected, const char *test);

int		expect_eq_ptr(void *ptr, void *expected, const char *test);

int		expect_null(void *ptr, const char *test);

int		expect_not_null(void *ptr, const char *test);

int		expect_true(int condition, const char *test);

int		expect_false(int condition, const char *test);

int		expect_content_fd(int fd, const char *expected, const char *test);

int		open_test_fd(void);

void	close_test_fd(int fd);

#endif /* end of include guard: TESTS_H */
