/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:23:04 by cruiz             #+#    #+#             */
/*   Updated: 2016/12/06 12:46:58 by cruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmpres;
	t_list	*tmplst;

	if (!lst || !f)
		return (NULL);
	tmplst = (*f)(lst);
	if ((res = ft_lstnew(tmplst->content, tmplst->content_size)))
	{
		tmpres = res;
		lst = lst->next;
		while (lst)
		{
			tmplst = (*f)(lst);
			if (!(tmpres->next =
						ft_lstnew(tmplst->content, tmplst->content_size)))
				return (NULL);
			tmpres = tmpres->next;
			lst = lst->next;
		}
		tmpres->next = NULL;
	}
	return (res);
}
