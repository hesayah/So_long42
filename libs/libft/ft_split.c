/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:10:30 by hesayah           #+#    #+#             */
/*   Updated: 2021/05/15 11:08:11 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	creat_tab(char **new, char *str, const char *set, int c_w)
{
	int	word;
	int len;
	int	index;

	word = 0;
	index = 0;
	while (word < c_w)
	{
		len = 0;
		while (str[index + len]
		&& ft_c_in_str(str[index + len], (char *)set) != 0)
			len++;
		new[word] = ft_substr(str, index, len);
		index += len;
		if (new[word] == NULL)
		{
			ft_free(new);
			return (0);
		}
		while (str[index] && ft_c_in_str(str[index], (char *)set) == 0)
			index++;
		word++;
	}
	new[c_w] = NULL;
	return (1);
}

static int	c_words(char *str, const char *set)
{
	int	i;
	int	words;

	i = 0;
	words = 1;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_c_in_str(str[i], (char *)set) == 0 && str[i + 1]
		&& ft_c_in_str(str[i + 1], (char *)set) == 1)
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *str, const char *set)
{
	int		c_w;
	int		ret;
	char	*tmp;
	char	**new;

	if (!str || !set)
		return (NULL);
	tmp = ft_strtrim(str, set);
	c_w = c_words(tmp, set);
	new = (char **)malloc(sizeof(char *) * (c_w + 1));
	if (new == NULL)
	{
		free(tmp);
		return (NULL);
	}
	ret = creat_tab(new, tmp, set, c_w);
	free(tmp);
	if (ret == 0)
		return (NULL);
	return (new);
}
