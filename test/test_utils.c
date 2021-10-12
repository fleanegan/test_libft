#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

char	*generate_random_string(size_t len)
{
	char	*result;
	char 	*possible_chars;

	possible_chars = "qwertyuiopasdfghjklzxcvbnm0123456789 \n\t";
	result = (char *) malloc(sizeof(char) * (len + 1));
	result[len] = 0;
	//srand(time(NULL));
	while (len-- > 0)
	{
		result[len] = possible_chars[rand() % 37];
	}
	return result;
}

void zero_array(char *arr, size_t size)
{
	for (size_t i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
