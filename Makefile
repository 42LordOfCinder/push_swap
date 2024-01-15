CC = clang

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

NAME_BONUS = checker

SRCS = main.c         \
	   ft_split.c      \
	   parsing_utils.c  \
	   swap.c            \
	   push.c             \
	   rotate.c            \
	   sort.c               \
	   sorting_utils.c       \
	   sorting_utils2.c       \
	   sorting_utils3.c        \

SRCS_BONUS = main_bonus.c        \
			 parsing_utils.c      \
			 swap.c                \
			 push.c                 \
			 rotate.c                \
			 lst_utils_bonus.c        \
			 utils_bonus.c             \
			 get_next_line.c            \
			 get_next_line_utils.c       \
			 sorting_utils.c              \
			 ft_split.c                    \

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@echo "Linking $@"
	@${CC} ${CFLAGS} $^ -o $@
	@echo "Done!"

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	@echo "Linking $@"
	@${CC} ${CFLAGS} $^ -o $@
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	@rm -rf ${OBJS} ${OBJS_BONUS}
	@echo "Done!"

fclean: clean
	@rm -rf ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re
