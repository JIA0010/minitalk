/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:50:24 by cjia              #+#    #+#             */
/*   Updated: 2023/06/09 14:28:36 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	total_size;
	void	*q;

	if (size && n > SIZE_MAX / size)
		return (NULL);
	total_size = n * size;
	q = malloc(total_size);
	if (q != NULL)
	{
		ft_memset(q, 0, total_size);
	}
	return (q);
}

// int	main(void)
// {
// 	int	*array;
// 	int	n;

// 	n = 5;
// 	array = (int *)ft_calloc(n, sizeof(int));
// 	if (array == NULL)
// 	{
// 		printf("メモリの割り当てに失敗しました。\n");
// 		return (1);
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		array[i] = i + 1;
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		printf("%d ", array[i]);
// 	}
// 	printf("\n");
// 	free(array);
// 	return (0);
// }
