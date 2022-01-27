#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	empty_string(char **line)
{
	*line = malloc(sizeof(char) * 1);
	if (!*line)
		return (0);
	*line[0] = '\0';
	return (1);
}

int	concat(char **rest, char *buffer, size_t len)
{
	char *tmp;
	size_t i = 0;

	tmp = malloc(sizeof(char) * len + 2);
	if (!tmp)
	{
		if (*rest)
		{	
			free(*rest);
		}
		return (0);
	}
	tmp[len + 1] = '\0';
	while (rest && *rest && (*rest)[i])
	{
		tmp[i] = (*rest)[i];
		i++;
	}
	tmp[i] = buffer[0];
	if (*rest)
	{
		free(*rest);
	}
	*rest = tmp;
	return (1);
}

int	get_next_line(char **line)
{
	char buffer[2];
	char *rest = NULL;
	int count = 0;

	if (!line)
		return (-1);
	*line = NULL;
	while ((count = read(0, buffer, 1)) > 0)
	{
		buffer[1] = '\0';
		if (buffer[0] == '\n')
		{
			if (!rest)
			{
				if (!empty_string(line))
					return (-1);
			}
			else
			{
				*line = rest;
			}
			return (1);
		}
		else
		{
			if (!concat(&rest, buffer, ft_strlen(rest)))
				return (-1);
		}
	}
	if (count < 0)
		return (-1);
	else
	{
		if (!rest)
		{
			if (!empty_string(line))
				return (-1);
		}
		else
		{
			*line = rest;
		}
	}
	return (0);
}
