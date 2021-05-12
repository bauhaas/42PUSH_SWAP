/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:07:08 by bahaas            #+#    #+#             */
/*   Updated: 2021/05/11 17:13:50 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "get_next_line.h"

static int	check_line(char *str)
{
	int				i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*grep_line(char *str)
{
	int				i;
	char			*dest;

	i = 0;
	if (!str)
	{
		dest = (char *)malloc(1);
		dest[0] = '\0';
		return (dest);
	}
	while (str[i] && str[i] != '\n')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*store_leftover(char *str, int i, int j)
{
	char			*dest;

	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!dest)
		return (NULL);
	i += 1;
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	if (dest[0] == '\0')
	{
		free(dest);
		dest = NULL;
	}
	free(str);
	return (dest);
}

int			get_next_line(const int fd, char **line)
{
	static char		*leftover;
	char			buf[BUFFER_SIZE + 1];
	int				ret;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	ret = 1;
	while (!check_line(leftover) && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		leftover = ft_strjoin(leftover, buf);
	}
	*line = grep_line(leftover);
	leftover = store_leftover(leftover, 0, 0);
	ret = (ret == 0 && ft_strlen(leftover) == 0) ? 0 : 1;
	return (ret);
}


/*
char	*prep_line(char *buff, char *line_result, int len)
{
	char	*line_end;
	int		i;

	i = 0;
	line_end = malloc(sizeof(char) * (len + 1));
	if (line_end == NULL)
		return (NULL);
	len = 0;
	while (buff[len] != '\n')
	{
		line_end[len] = buff[len];
		len++;
	}
	line_end[len] = 0;
	while (buff[++len])
	{
		buff[i] = buff[len];
		i++;
	}
	buff[i] = 0;
	if (!(line_result = ft_strjoin(line_result, line_end)))
		return (NULL);
	free(line_end);
	return (line_result);
}

int		ft_read_line(int fd, char **line, char *buff, char *line_result)
{
	int len;
	int ret;

	ret = 1;
	while ((len = ft_check_buffer_nl(buff)) == -1 && ret > 0)
	{
		if (!(line_result = ft_strjoin(line_result, buff)))
			return (-1);
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = 0;
	}
	if ((len = ft_check_buffer_nl(buff)) != -1)
	{
		if (!(*line = prep_line(buff, line_result, len)))
			return (-1);
		return (1);
	}
	if (!(*line = ft_strjoin(line_result, buff)))
		return (-1);
	if (ret == 0)
		return (0);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line_result;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0 || !line)
		return (-1);
	line_result = malloc(sizeof(char) * 1);
	if (line_result == NULL)
		return (-1);
	line_result[0] = '\0';
	return (ft_read_line(fd, line, buff, line_result));
}
*/
