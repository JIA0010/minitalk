/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:22:02 by cjia              #+#    #+#             */
/*   Updated: 2023/05/29 17:06:48 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*q;

	q = (unsigned char *)s;
	while (n--)
	{
		if (*q == (unsigned char)c)
			return (q);
		q++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char str[] = "Hello, World!";
// 	char *p = ft_memchr(str, 'W', sizeof(str));
// 	if (p != NULL)
// 		printf("Wあり");
// 	else
// 		printf("Wなし");
// 	return (0);
// }