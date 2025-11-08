int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    int i;

    i = 0;
    while (i < size - 1 && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
}


#include <string.h>
#include <stdio.h>
/*int main()
{
    char dest[4];
    printf("%lu", strlcpy(dest, "hello", 4));
    printf("%s", dest);
}
    */

int main(int argc, char **argv)
{
    (void)argc;

    char dest[5];
    printf("%u\n", ft_strlcpy(dest, argv[1], 5));
    printf("%s", dest);
}