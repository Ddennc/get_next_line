// #include "get_next_line.h"

// int main()
// {
//     int fd;
//     char *result;
//     int lines = 0;

//     fd = open("text.txt", O_RDONLY);
//     if (fd < 0)
//         return (1);

//     while ((result = get_next_line(fd))) {
//         printf("Line %d: %s\n", ++lines, result);
//         free(result); // Освобождаем память, выделенную get_next_line
//     }

//     close(fd);
//     return (0);
// }
