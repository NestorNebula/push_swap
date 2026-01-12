NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm

RMFLAGS = -r -f

LIBFT_DIR = libft

LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/include

LIBFT = ft

LIBFT_LIB = $(LIBFT_DIR)/lib$(LIBFT).a

INCLUDE_DIR = include

SRC_DIR = src

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/stack.c $(SRC_DIR)/parse.c \
	  $(SRC_DIR)/operations.c

OBJ = $(SRC:.c=.o)

LDFLAGS = -L$(LIBFT_DIR) -l$(LIBFT)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(LIBFT_INCLUDE_DIR) -I$(INCLUDE_DIR)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

$(LIBFT_LIB):
	$(MAKE) bonus -C $(LIBFT_DIR)

clean:
	$(RM) $(RMFLAGS) $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:
	$(RM) $(RMFLAGS) $(OBJ)
	$(RM) $(RMFLAGS) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
