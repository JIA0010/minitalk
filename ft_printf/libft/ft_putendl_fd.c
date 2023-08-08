/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:31:19 by cjia              #+#    #+#             */
/*   Updated: 2023/06/02 15:40:17 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*q;
	int		q_len;

	if (s == NULL)
		return ;
	q = s;
	q_len = ft_strlen(q);
	while (q_len--)
	{
		write(fd, q, 1);
		q++;
	}
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	char *message = "Hello, World!";

// 	ft_putendl_fd(message, 1);

// 	return (0);
// }