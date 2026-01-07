#include "libtests.h"

#define BUFFSIZE 4096
#define FILENAME "testfile"

int	expect_content_fd(int fd, const char *expected, const char *test)
{
	char	buf[BUFFSIZE];
	int		n;

	lseek(fd, 0, SEEK_SET);
	n = read(fd, buf, BUFFSIZE - 1);
	if (n < 0)
	{
		printf("\n%s: can't read the data from file descriptor\n", test);
		return (1);
	}
	buf[n] = '\0';
	if (strcmp(buf, expected) != 0)
	{
		printf("\n%s: expected \"%s\", got \"%s\"\n",
			test, expected, buf);
		return (1);
	}
	return (0);
}

int		open_test_fd(void)
{
	int	fd;

	fd = open(FILENAME, O_CREAT | O_RDWR, S_IRWXU);
	return (fd);
}

void	close_test_fd(int fd)
{
	close(fd);
	remove(FILENAME);
}
