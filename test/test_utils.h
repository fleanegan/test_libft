#ifndef TEST_UTILS_H
# define TEST_UTILS_H
# include <unistd.h>
# include <stdio.h>
# define SPACE_FOR_TERMINATING_CHAR 1
char	*generate_random_string(size_t len);
void	zero_array(char *arr, size_t size);
void	ft_putstr(char *str);
#endif	 // TEST_UTILS_H
