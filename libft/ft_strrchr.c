/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:59:57 by dmodrzej          #+#    #+#             */
/*   Updated: 2024/03/09 14:07:15 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*find;

	find = (char *)str;
	i = ft_strlen(find);
	while (i >= 0)
	{
		if ((unsigned char)find[i] == (unsigned char)c)
			return (&find[i]);
		i--;
	}
	return (0);
}
