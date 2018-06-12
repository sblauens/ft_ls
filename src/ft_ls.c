/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblauens <sblauens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:59:22 by sblauens          #+#    #+#             */
/*   Updated: 2018/06/12 04:08:21 by sblauens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_options			g_options;

void				iter_file_args(t_list *file_args)
{
	while (file_args)
	{
		list_dir_content((char *)file_args->content);
		file_args = file_args->next;
		if (file_args)
			ft_putstr("\n");
	}
}

void				parse_file_args(char **av)
{
	size_t			arg_len;
	t_list			*file_args;
	t_list			*node;

	file_args = NULL;
	while (*av)
	{
		node = NULL;
		arg_len = ft_strlen(*av);
		if (!(node = ft_lstnew(*av, arg_len)))
			return ;
		if (!file_args)
			file_args = node;
		else
			ft_lstadd_bck(&file_args, node);
		++av;
	}
	ft_lstsort_merge(&file_args, &cmp_dirname);
	iter_file_args(file_args);
	ft_lstdel(&file_args, &del_file_node);
}

int					main(int ac, char **av)
{
	unsigned int	n;

	n = 1;
	default_options();
	if (ac > 1)
	{
		while (*(av + n))
		{
			if (**(av + n) == '-')
				parse_option_args(*(av + n) + 1);
			else
				break ;
			++n;
		}
	}
	if (ac - n > 1 || g_options.recursive)
		g_options.multi_files = 1;
	if (*(av + n))
		parse_file_args(av + n);
	else
		list_dir_content(".");
	return (0);
}
