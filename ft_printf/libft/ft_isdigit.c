/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:20:30 by cjia              #+#    #+#             */
/*   Updated: 2023/06/09 15:04:49 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// int	main(void)
// {
// 	char str;
// 	printf("一文字入力せよ");
// 	scanf("%c", &str); // &strではない
// 	printf("%d\n", ft_isdigit(str));
// 	return (0);
// }