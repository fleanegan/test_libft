MAIN				= test_main.c

NAME				= test_executable.o

CC					= gcc

RM					= rm -f

LIBNAMELIBFT		=	../src/libft.a

$(LIBNAMELIBFT):
					$(MAKE) -C 	../src/ all

ILIBFT				= -L../src -l:libft.a

ICRITERION			= -L../criterion-v2.3.3/lib -I../criterion-v2.3.3/include -lcriterion -Wl,-rpath=../criterion-v2.3.3/lib

CFLAGS				= -Wall -Wextra -Werror

${NAME}:			$(LIBNAMELIBFT)
					${CC} ${CFLAGS} -o $(NAME) ../src/libft.h $(MAIN) $(ICRITERION) $(ILIBFT)

# defines "own_source", which allows for including tests specific to your code with #ifndef
test_own:			$(LIBNAMELIBFT)
					${CC} ${CFLAGS} -D own_source -o $(NAME) ../src/libft.h $(MAIN) $(ICRITERION) $(ILIBFT)

all:				${NAME}

compile_with_no_flags:
					${CC} -o $(NAME) ../src/libft.h $(MAIN) $(ICRITERION) $(ILIBFT)
fclean:
					${RM} ${NAME}

re:					fclean all

re_no_flags: 		fclean compile_with_no_flags

run: 				re
	@./$(NAME)

run_no_flags: 		re_no_flags
	@./$(NAME)


