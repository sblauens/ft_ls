/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblauens <sblauens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:59:22 by sblauens          #+#    #+#             */
/*   Updated: 2018/06/12 16:56:24 by sblauens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_options			g_options;

int					main(int ac, char **av)
{
	int			n;

	n = 1;
	check_options(ac, av, &n);
	check_files(av + n);
	return (0);
}
