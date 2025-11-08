int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    int i;
    int dest_len;

    i = 0;
    dest_len = ft_strlen(dest);
    while (src[i] && dest_len + i < size)
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest_len + ft_strlen(src));
}

#include <stdio.h>
int main()
{
    char dest[10] = "hello";
    char src[] = "byebye";
    printf("%d\n", ft_strlcat(dest, src, 10));
    printf("%s", dest);
}