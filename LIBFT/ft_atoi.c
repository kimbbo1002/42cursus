/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:24:44 by bokim             #+#    #+#             */
/*   Updated: 2025/11/10 11:44:20 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int count;
	int	res;

	i = 0;
	count = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || 
		str[i] == '\n' || str[i] == '\v' || str[i] == 'f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			count = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (count * res);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // string to be converted
    char strToConvert[] = "geeksforgeeks";

    // converting string using atoi()
    int ConvertedStr = ft_atoi(strToConvert);

    // printing the Converted String
    printf("String to be Converted: %s\n", strToConvert);
    printf("Converted to Integer: %d\n", ConvertedStr);

    return 0;
}
	*/
/*
#include <stdio.h>

int main()
{
    const char strg[] = "12345";
    int value = ft_atoi(strg);

    // print the Converted Value
    printf("String to be Converted: %s\n", strg);
    printf("Converted to Integer: %d\n", value);
    return 0;
}
*/