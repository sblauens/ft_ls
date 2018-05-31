/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblauens <sblauens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:52:11 by sblauens          #+#    #+#             */
/*   Updated: 2018/05/31 14:03:39 by sblauens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

#include "libft.h"
#include "options.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>

typedef struct			s_file
{
	off_t				size;
	char				filename[256];
	char				pathname[256];
	struct timespec		*date;
}						t_file;

int						list_dir_content(char *dir_name);
int						get_dir_content(char *dir_name, DIR *dir_stream,
											t_list **dir_files);
void					print_dir_content(t_list *dir_files);
void					del_file_node(void *content, size_t size);
void					default_options();
void					parse_option_args(char *arguments);
int						cmp_filename(void *f1, void *f2);
int						cmp_dirname(void *d1, void *d2);
#endif
