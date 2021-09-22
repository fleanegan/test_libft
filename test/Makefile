SRCS	= $(shell find ../src/ -type f -name "*.c")

MAIN	= test_main.c

NAME	= test_executable.o

CC		= gcc

RM		= rm -f

LDIR	= ../criterion-v2.3.3/lib

IDIR	= ../criterion-v2.3.3/include

LIBS	= -lcriterion

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	$(SRCS)
			${CC} ${CFLAGS} -o $(NAME) $(MAIN) $(SRCS) -I$(IDIR) -L$(LDIR) $(LIBS)

# defines "own_source", which allows for including tests specific to your code with #ifndef
test_own:	$(SRCS)
			${CC} ${CFLAGS} -D own_source -o $(NAME) $(MAIN) $(SRCS) -I$(IDIR) -L$(LDIR) $(LIBS)

all:		${NAME}

compile_with_no_flags:
			${CC} -o $(NAME) $(SRCS) -I$(IDIR) -L$(LDIR) $(LIBS)

fclean:
			${RM} ${NAME}

re:			fclean all

re_no_flags: fclean compile_with_no_flags

run: re
	@./$(NAME)

run_no_flags: re_no_flags
	@./$(NAME)


