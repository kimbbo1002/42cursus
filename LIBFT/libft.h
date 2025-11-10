#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

// libc functions
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isascii(int c);

int	ft_toupper(int c);
int	ft_tolower(int c);

int	ft_atoi(const char *str);

int	ft_strlen(const char *str);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(char *str, int c);
char	*ft_strnstr(const char *big, const char *little, size_t n);

void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*memchr(const void *str, int c, size_t n);
int ft_memcmp(const void *str1, const void *str2, size_t n);

void	*ft_calloc(size_t n, size_t size);
char	*ft_strdup(const char *str);

//additional functions

#endif