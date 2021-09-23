SRCS				= $(shell find ../src/ -type f -name "*.c" -o -name "*.h")

TEST_FILES			= $(shell find ./ -type f -name "*.h" -o -name "*.c")

MAIN				= test_main.c

NAME				= test_executable.o

CC					= gcc -lbsd

RM					= rm -f

LIBNAMELIBFT		=	../src/libft.a

$(LIBNAMELIBFT):	$(SRCS)
					$(MAKE) -C 	../src/ all

ILIBFT				= -L../src -l:libft.a

ICRITERION			= -L../criterion-v2.3.3/lib -I../criterion-v2.3.3/include -lcriterion -Wl,-rpath=../criterion-v2.3.3/lib

CFLAGS				= -Wall -Wextra -Werror

${NAME}:			$(LIBNAMELIBFT) $(SRCS) $(TEST_FILES)
					${CC} ${CFLAGS} -o $(NAME) $(MAIN) $(ICRITERION) $(ILIBFT)

# defines "own_source", which allows for including tests specific to your code with #ifndef
test_own:			$(LIBNAMELIBFT) $(SRCS) $(TEST_FILES)
					${CC} ${CFLAGS} -D own_source -o $(NAME) $(MAIN) $(ICRITERION) $(ILIBFT)

all:				${NAME}

compile_with_no_flags: $(SRCS) $(TEST_FILES)
					${CC} -o $(NAME) $(MAIN) $(ICRITERION) $(ILIBFT)
fclean:
					${RM} ${NAME}

re:					fclean all

re_no_flags: 		fclean compile_with_no_flags

run: 				re
	@./$(NAME)

run_no_flags: 		re_no_flags
	@./$(NAME)


