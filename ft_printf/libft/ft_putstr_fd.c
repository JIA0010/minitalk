/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:31:54 by cjia              #+#    #+#             */
/*   Updated: 2023/06/13 11:15:23 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	char	*q;
	int		q_len;

	if (s == NULL)
		return ;
	q = s;
	q_len = ft_strlen(q);
	write(fd, q, q_len);
}

// int main() {
//     char *message = "Hello, World!";

//     ft_putstr_fd(message, 1);

//     return (0);
// }