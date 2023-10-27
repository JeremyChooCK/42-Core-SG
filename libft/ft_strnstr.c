/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:17:18 by jechoo            #+#    #+#             */
/*   Updated: 2023/09/06 17:55:09 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	if (str[0] == '\0' || str == NULL)
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (to_find[j] != '\0' && str[i + j] == to_find[j] && i + j < len)
		{
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
/*char	*ft_strnstr2(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!*needle)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
			if (!needle[++j])
				return ((char *) haystack + i);
		i++;
	}
	return (0);
}
#include<bsd/string.h>
#include<stdio.h>
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}
int	main()
{

	if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15)))
		ft_print_result("NULL");
	else
		ft_print_result(str);
	printf("ft: %s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
	printf("ft: %s\n", ft_strnstr2("lorem ipsum dolor sit amet", "dolor", 15));
	printf("og: %s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 15));
}*/
