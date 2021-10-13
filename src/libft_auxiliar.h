#ifndef LIBFT_AUXILIAR_H
# define LIBFT_AUXILIAR_H

# include <stdlib.h>

int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isspace(int input);
size_t	count_trimmable_leading_chars(const char *src, const char *set);
size_t	count_trimmable_trailing_chars(const char *src, const char *set);
int		is_char_in_set(char in, const char *set);
#endif
