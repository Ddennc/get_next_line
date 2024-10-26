/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denysdudka <denysdudka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:11:32 by ddudka            #+#    #+#             */
/*   Updated: 2024/10/26 13:02:12 by denysdudka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(char *buffer,char *left_c, int fd)
{
	ssize_t chars_read;
	char *tmp;
	
	chars_read = 1;
	while(chars_read)
	{
	chars_read = read(fd,buffer,BUFFER_SIZE);
	if (chars_read < 0)
	{
			free(left_c);
			return (NULL);
		}
	else if (!chars_read)
	break;
	buffer[chars_read] = '\0';
	if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	return (left_c);
} 

char *remainded_string(char *line)
{
	char *left_c;
	ssize_t i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0)
		return (NULL);
	left_c = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line[i + 1] = 0;
	return (left_c);
}
char *get_next_line(int fd)
{
	char *line;
	char *buf;
	static char *left_c;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		return (NULL);
	}
	buf = calloc(BUFFER_SIZE + 1,sizeof(char));
	if (!buf)
		return (NULL);
	line = read_line(buf,left_c,fd);
	free(buf);
	if (!line)
		return (NULL);
	left_c = remainded_string(line);
	return (line);
}
// int main()
// 	{
// 		int fd;
// 		char* dummy;
// 		fd = open("text.txt",O_RDONLY);
// 		int readres = read(fd,dummy,0);
// 		if(fd < 0 || readres < 0)
// 			return 0;
			
// 		printf("%s",dummy);
// 	}
// int main()
// {
// 	// OPEN 
// 	//open() function opens a file and we receive new fd
// 	// open(path to file, flags, mode fo create flag(644 rewr for me and re for others))
// 	//O_RDONLY read only
// 	//O_WRONLY write only
// 	//O_RDWR read and write
// 	//O_CREAT create file if its not exist(using mode(644))
// 	//O_APPEND dobavit dannye v konec faila
// 	//O_TRUNC udalit vse dannye iz faila
// 	//vozrashaet nomer fd , esli oshibka to -1
// 	// | znak obyedenyet neskolko flagov 
// 	// OPEN PRIMERY
// 	// int fd;
// 	// int fdr;
// 	// fd = open("text.txt",O_RDWR);
// 	// fdr = open("hello.txt",O_RDWR);
// 	// printf("fd of file fd :%d\n",fd);
// 	// write(1, "hello", 5);
// 	// write(fd, "hello", 5);
// 	// //zapisivaem v fd hello
// 	// dup2(fd,fdr);
// 	// // teper fdr ukazivaet na text.txt i vse chto budet zapisivatsa v fdr budet napravlyatsy tuda
// 	// write(fdr,"he", 2);
// 	// //zapisivaetsy ne v hello.txt a v text.txt
// 	// dup2(fd, 1);
// 	// // vmesto toho chtob vypisivat v teminal pishem v text.txt
// 	// write(1,"term",4);
// 	// READ
// 	// read(fd, buf,number of bytes we want to copy into buffer from fd)
// 	// char buf[1024] buffer(massiv) na 1024 yacheiki pamyati
// 	// read(3,buf,10); Read from fd 3 into buf 10 bytes per call
// 	// functsiya read pri perevyzove nachinaet s toho mesta gde my zakonchili
// 	// read vozrashaet kolichestvo skopirovanych symvolov
// 	// READ PRIMER
// 	// int fd;
// 	// char buf[255];
// 	// int chars_read;
// 	// fd = open("text.txt",O_RDONLY);
// 	// while((chars_read = read(fd,buf,25)))
// 	// {
// 	// 	buf[chars_read] = '\0';
// 	// 	printf("buf->%s\n",buf);
// 	// }
	
	
// }
// // 0 - stdin
// // 1 - stdout
// // 2 - stderr
// // ps - shows all the programs that are runninng
// // lsof -p (PID) showing all the files used by specific proces
// // tty - shows the terminal which you are using
// // echo "hello" > /dev/tty redirects message to another terminal vim /dev/pts/3
// // vim /dev/pts/3 we can open and write text which then will appear in terminal output(then its deleting)
// // everytime we are calling write function we are writing something in redactor and then its appear in output

