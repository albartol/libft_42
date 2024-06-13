/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:10:21 by albartol          #+#    #+#             */
/*   Updated: 2024/06/14 00:13:48 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*array_to_str(const char **array, const char spliter)
{
	char	*str;
	char	split[2];
	size_t	len;
	int		i;

	if (spliter)
	{
		split[0] = spliter;
		split[1] = 0;
		len = array_char_len(array) + array_len(array);
	}
	else
		len = array_char_len(array);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (array[i])
	{
		ft_strlcat(str, array[i], len + 1);
		i++;
		if (spliter && array[i])
			ft_strlcat(str, split, len + 1);
	}
	return (str);
}
