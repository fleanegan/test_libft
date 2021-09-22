# test_libft
This project allows to test the functions necessary for libft and is based on the test framework criterion (https://github.com/Snaipe/Criterion). I would be glad to receive comments and suggestions in order to improve the test quality and readability.
Comes with no warranty whatsoever.

Installation of criterion
---
Follow the instructions on the official criterion git hub page for your setup OR
run the following code in the test_libft root directory:

```
wget https://github.com/Snaipe/Criterion/releases/download/v2.3.3/criterion-v2.3.3-linux-x86_64.tar.bz2
tar -xf criterion-v2.3.3-linux-x86_64.tar.bz2
rm criterion-v2.3.3-linux-x86_64.tar.bz2
```

Test execution
---
The Makefile can be used to compile and run the tests with all the necessary source files.
Run the following command in the root directory:
```
make run_tests
```
which compiles with all the flags also used by the Moulinette. To compile without them run

```
make run_tests_compile_no_flags
```
