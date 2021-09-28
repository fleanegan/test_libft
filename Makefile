run_tests:
			$(MAKE) -C 	./test/ run

run_tests_compile_no_flags:
			$(MAKE) -C 	./test/ run_no_flags

re:			fclean all

all:
			$(MAKE) -C 	./test/ all

run: all
	@./$(NAME)
