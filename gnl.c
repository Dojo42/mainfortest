/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofaure <thofaure@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:11:29 by thofaure          #+#    #+#             */
/*   Updated: 2025/01/27 12:17:44 by thofaure         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char *gnl(int fd)
{
	static char buffer[BUFFER_SIZE];
	char	line[70000];
	int		i;
	static int buffer_pos;
	static int buffer_read;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break;
		}
		line[i++] = buffer[buffer_pos++];
		if (buffer_pos - 1 == '\n')
			break;
	}
	line[i] = '\0';
	retunr (ft_strdup(line));
}