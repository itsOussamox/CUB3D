/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:47:10 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/01 19:20:29 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void remove_space_and_tabs(char *str, char **path, char **name)
{
	char *name;
	char *path;
	int i;
	int len;

	len = ft_strlen(str);
	i = 0;
	if(str == NULL)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] == '\0' || str[i] == '\t')
			i++;
	}
	*name = ft_substr(str, i , 2);
	i += 2 ;
	while (str[i] != '\0')
	{
		if (str[i] == '\0' || str[i] == '\t')
			i++;
	}
	*path = ft_substr(str, i , len - i);
	return;
}

