/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 18:26:47 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/02 12:38:14 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Looks for '\n' in string and returns the index if found, else -1.
static int	find_nl(char *line);

/* If parameter passed in contains '\n', fix_line() trims the end of the line
** and returns a pointer to it. Else if just return the line. */
static char	*fix_line(char *line);

/* The rem_line() function handles the remaining character after '\n' and
** stores them back in the static variable of get_next_line(). */
static char	*rem_line(char *line);

static int	find_nl(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (-1);
	return (i);
}

static char	*fix_line(char *line)
{
	char	*till_nl;
	int		pos_nl;

	if (!line)
		return (NULL);
	pos_nl = find_nl(line);
	if (find_nl(line) == -1)
		return (ft_strdup(line));
	till_nl = malloc(pos_nl + 2);
	if (!till_nl)
		return (NULL);
	ft_memmove(till_nl, line, pos_nl);
	till_nl[pos_nl] = '\n';
	till_nl[pos_nl + 1] = '\0';
	return (till_nl);
}

static char	*rem_line(char *line)
{
	int		pos_nl;
	int		len;

	if (!line)
		return (NULL);
	pos_nl = find_nl(line);
	len = ft_strlen(line);
	if (pos_nl == -1 || (pos_nl - len) == -1)
	{
		free(line);
		return (NULL);
	}
	line = gnl_substr(line, (pos_nl + 1), (len - pos_nl - 1));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*till_nl;
	char		*buff;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (find_nl(line) == -1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buff[bytes_read] = '\0';
		line = gnl_strjoin(line, buff);
	}
	free(buff);
	till_nl = fix_line(line);
	line = rem_line(line);
	return (till_nl);
}
