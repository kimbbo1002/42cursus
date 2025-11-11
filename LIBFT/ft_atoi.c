/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:24:44 by bokim             #+#    #+#             */
/*   Updated: 2025/11/11 16:17:34 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	count;
	int	res;

	i = 0;
	count = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
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

int	main(void)
{
	char	strToConvert[];
	int		ConvertedStr;

    // string to be converted
    strToConvert[] = "geeksforgeeks";
    // converting string using atoi()
    ConvertedStr = ft_atoi(strToConvert);
    // printing the Converted String
    printf("String to be Converted: %s\n", strToConvert);
    printf("Converted to Integer: %d\n", ConvertedStr);
    return (0);
}
	*/
/*
#include <stdio.h>

int	main(void)
{
	const char	strg[];
	int			value;

    strg[] = "12345";
    value = ft_atoi(strg);
    // print the Converted Value
    printf("String to be Converted: %s\n", strg);
    printf("Converted to Integer: %d\n", value);
    return (0);
}
*/