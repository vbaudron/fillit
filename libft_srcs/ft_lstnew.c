/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:14:52 by cruiz             #+#    #+#             */
/*   Updated: 2016/11/28 11:23:46 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		if (content == NULL)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			new->content = malloc(sizeof(content));
			if (!new->content)
				return (NULL);
			else
			{
				ft_memcpy(new->content, content, content_size);
				new->content_size = content_size;
			}
		}
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
