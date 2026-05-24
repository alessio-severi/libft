/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:11:55 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/27 19:44:29 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_init(t_list *lst, t_list **begin_trasform_lst,
	void *(*f)(void *), void (*del)(void *))
{
	void	*trasform_content;

	trasform_content = f(lst->content);
	*begin_trasform_lst = ft_lstnew(trasform_content);
	if (!(*begin_trasform_lst))
	{
		del(trasform_content);
		return (1);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	t_list	*trasform_lst;
	t_list	*begin_trasform_lst;
	void	*trasform_content;

	if (!lst || !f || !del)
		return (NULL);
	if (ft_init(lst, &begin_trasform_lst, f, del))
		return (NULL);
	trasform_lst = begin_trasform_lst;
	while (lst->next)
	{
		trasform_content = f((lst->next)->content);
		trasform_lst->next = ft_lstnew(trasform_content);
		if (!(trasform_lst->next))
		{
			del(trasform_content);
			ft_lstclear(&begin_trasform_lst, del);
			return (NULL);
		}
		trasform_lst = trasform_lst->next;
		lst = lst->next;
	}
	return (begin_trasform_lst);
}
