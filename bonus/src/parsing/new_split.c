/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:31:22 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/09 19:42:23 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	check_if_split_value(char c, char *split_value)
{
	int	i;

	i = 0;
	while (split_value[i] != '\0')
	{
		if (c == split_value[i])
			return (-1);
		i++;
	}
	if (c == '\0')
		return (-1);
	return (0);
}

void	fill_string(char *dst, char *src, char *split_value)
{
	int	i;

	if (dst == NULL)
	{
		printf("Error: malloc\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (check_if_split_value(src[i], split_value) == 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

char	**fill_tab(char *str, char *split_value, int word_count, int i)
{
	char	**tab;
	int		word_len;

	tab = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (tab == NULL)
		return (NULL);
	tab[word_count] = NULL;
	word_count = 0;
	while (str[i] != '\0')
	{
		if (check_if_split_value(str[i], split_value) == -1)
			i++;
		else
		{
			word_len = 0;
			while (check_if_split_value(str[i + word_len], split_value) == 0)
				word_len++;
			tab[word_count] = (char *)malloc(sizeof(char) * (word_len + 1));
			fill_string(tab[word_count], str + i, split_value);
			i += word_len;
			word_count++;
		}
	}
	return (tab);
}

int	get_number_of_tabs(char *str, char *split_value)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (check_if_split_value(str[i], split_value) == 0
			&& check_if_split_value(str[i + 1], split_value) == -1)
			count++;
		i++;
	}
	return (count);
}

char	**clear_tabs_and_spaces(char *str, char *split_value)
{
	char	**tab;
	int		word_count;

	word_count = get_number_of_tabs(str, split_value);
	tab = fill_tab(str, split_value, word_count, 0);
	if (tab == NULL)
	{
		printf("Error: malloc\n");
		return (NULL);
	}
	return (tab);
}
