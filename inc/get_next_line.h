/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 18:26:40 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/02 12:37:51 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "libft.h"

// Function that returns a line read from a file descriptor (incuding '\n').
char	*get_next_line(int fd);

// Modified version of ft_strjoin() that now has free() functionality
char	*gnl_strjoin(char const *s1, char const *s2);

// Modified version of ft_substr() that now has free() functionality
char	*gnl_substr(char const *s, unsigned int start, size_t len);

#endif
