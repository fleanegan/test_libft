SRCS				= $(shell find ../src/ -type f -name "*.c" -o -name "*.h")

TEST_HEADERS		= $(shell find ./ -type f -name "*.h")

TEST_SOURCES		= $(shell find ./ -type f -name "*.c")

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

${NAME}:			$(LIBNAMELIBFT) $(SRCS) $(TEST_HEADERS) $(TEST_SOURCES)
					${CC} ${CFLAGS} -o $(NAME) $(TEST_SOURCES) $(ICRITERION) $(ILIBFT)

# defines "own_source", which allows for including tests specific to your code with #ifndef
test_own:			$(LIBNAMELIBFT) $(SRCS) $(TEST_FILES)
					${CC} ${CFLAGS} -D own_source -o $(NAME) $(TEST_SOURCES) $(ICRITERION) $(ILIBFT)

all:				${NAME}

compile_with_no_flags: $(SRCS) $(TEST_FILES)
					${CC} -o $(NAME) $(TEST_SOURCES) $(ICRITERION) $(ILIBFT)
fclean:
					${RM} ${NAME}

re:					fclean all

re_no_flags: 		fclean compile_with_no_flags

run: 				re
	@./$(NAME)

run_no_flags: 		re_no_flags
	@./$(NAME)


