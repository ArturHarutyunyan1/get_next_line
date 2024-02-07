#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

// char *get_next_line(int fd);
t_list *read_file(int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024

#endif