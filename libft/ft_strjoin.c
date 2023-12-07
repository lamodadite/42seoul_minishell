/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:35:12 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/11 13:29:08 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	index;
	char	*toss;

	if (s1 == 0 || s2 == 0)
		return (0);
	index = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	toss = (char *)ft_calloc(total_len + 1, sizeof(char));
	if (toss == 0)
		return (0);
	ft_strlcat(toss, s1, total_len + 1);
	ft_strlcat(toss, s2, total_len + 1);
	return (toss);
}
