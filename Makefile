run_tests:
			$(MAKE) -C 	./test/ run

run_tests_compile_no_flags:
			$(MAKE) -C 	./test/ run_no_flags

re:			fclean all

all:
			run_tests

run: all
	@./$(NAME)
