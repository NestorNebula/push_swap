TESTS_DIR = src

TESTS_M = 
TESTS_B = 
TESTS_F = $(TESTS_DIR)/stack.c $(TESTS_DIR)/parse.c $(TESTS_DIR)/operations.c

TESTS = $(TESTS_M) $(TESTS_B) $(TESTS_F)

EXECS_M = $(TESTS_M:.c=.out)
EXECS_B = $(TESTS_B:.c=.out)
EXECS_F = $(TESTS_F:.c=.out)
EXECS = $(TESTS:.c=.out)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm

RMFLAGS = -rf

VALGRIND = valgrind

VALGRIND_FLAGS = --leak-check=full

TESTS_LIB_DIR = libtests

TESTS_LIB_INCLUDE_DIR = $(TESTS_LIB_DIR)/include

TESTS_LIB_NAME = tests

TESTS_LIB = $(TESTS_LIB_DIR)/lib$(TESTS_LIB_NAME).a

LIBFT_DIR = libft

LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/include

LIBFT = ft

LIBFT_LIB = $(LIBFT_DIR)/lib$(LIBFT).a

ROOT_DIR = ..

INCLUDE_DIR = $(ROOT_DIR)/include

SRC_DIR = $(ROOT_DIR)/src

SRC = $(SRC_DIR)/stack.c $(SRC_DIR)/parse.c $(SRC_DIR)/operations.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = 

LDFLAGS = -L$(TESTS_LIB_DIR) -l$(TESTS_LIB_NAME) -L$(LIBFT_DIR) -l$(LIBFT)

INCLUDES = -I$(INCLUDE_DIR) -I$(TESTS_LIB_INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)

all: $(EXECS)

%.out: %.c $(SRC) $(TESTS_LIB) $(LIBFT_LIB)
	$(MAKE) -C $(ROOT_DIR)
	$(CC) $(CFLAGS) -o $@ $< $(OBJ) $(LDFLAGS) $(INCLUDES)

$(TESTS_LIB):
	$(MAKE) -C $(TESTS_LIB_DIR)

$(LIBFT_LIB):
	$(MAKE) bonus -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(ROOT_DIR)
	$(MAKE) clean -C $(TESTS_LIB_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:
	$(MAKE) fclean -C $(ROOT_DIR)
	$(MAKE) fclean -C $(TESTS_LIB_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(RMFLAGS) $(EXECS)

re: fclean all

define do_tests
	echo "\nMaking $(1) tests...\n"
	sleep 2s
	for test in $(2) ; do \
		sleep 0.5s ; \
		./$$test ; \
	done
endef

define do_tests_extend
	echo "\nMaking $(1) tests...\n"
	sleep 2s
	for test in $(2) ; do \
		sleep 0.5s ; \
		$(VALGRIND) $(VALGRIND_FLAGS) ./$$test ; \
	done
endef

a: $(EXECS)
	@$(call do_tests,"all",$(EXECS))

m: $(EXECS_M)
	@$(call do_tests,"mandatory",$(EXECS_M))

b: $(EXECS_B)
	@$(call do_tests,"bonus",$(EXECS_B))

f: $(EXECS_F)
	@$(call do_tests,"functions",$(EXECS_F))

ae: $(EXECS)
	@$(call do_tests_extend,"all",$(EXECS))

me: $(EXECS_M)
	@$(call do_tests_extend,"mandatory",$(EXECS_M))

be: $(EXECS_B)
	@$(call do_tests_extend,"bonus",$(EXECS_B))

fe: $(EXECS_F)
	@$(call do_tests_extend,"functions",$(EXECS_F))
