LIB = libtests.a

AR = ar

ARFLAGS = -r -c -s

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm

RMFLAGS = -rf

INCLUDE_DIR = include

INCLUDE = $(INCLUDE_DIR)/libtests.h

SRC_DIR = src

SRC = $(SRC_DIR)/compare.c $(SRC_DIR)/test_fd.c

OBJ = $(SRC:.c=.o)

all: $(LIB)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDE_DIR)

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(RMFLAGS) $(OBJ)

fclean: clean
	$(RM) $(RMFLAGS) $(LIB)

re: fclean all
