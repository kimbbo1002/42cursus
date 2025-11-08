int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int i;

    i = 0;
    while (i < n && (s1[i] || s2[i]))
    {
        if (s1[i] == s2[i])
            i++;
        else if (s1[i] > s2[i])
            return 1;
        else
            return -1;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
    (void)argc;
    printf("%d", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
}