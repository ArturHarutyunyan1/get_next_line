#include "get_next_line.h"
#include <fcntl.h>
t_list *read_file(int fd)
{
    char buffer[BUFFER_SIZE];
    char *temp;
    int byte;
    int i;
    t_list *node;
    t_list *list;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    i = 0;
    byte = 1;
    list = NULL;
    temp = (char *)malloc(BUFFER_SIZE + 1);
    if (!temp)
        return (NULL);
    while (byte > 0)
    {
        byte = read(fd, buffer, 1);
        temp[i++] = buffer[0];
        if (buffer[0] == '\n')
        {
            temp[i] = '\0';
            node = ft_lstnew(strdup(temp));
            if (!temp)
            {
                free (temp);
                return (NULL);
            }
            ft_lstadd_back(&list, node);
            i = 0;
        }
    }
    free (temp);
    return (list);
}


int main()
{
    int fd = open("movses", O_RDONLY);

    if (fd < 0)
    {
        perror("Error opening file");
        return 1;  // Exit with an error code
    }

    t_list *result = read_file(fd);
    close(fd);  // Close the file descriptor after reading
    int i = 0;
    while (result != NULL)
    {
        printf("line %d - %s", i++ ,(char *)result->content);
        t_list *temp = result;
        result = result->next;
        free(temp->content);  // Free the content
        free(temp);           // Free the node
    }

    return 0;  // Exit successfully
}