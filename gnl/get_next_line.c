#include "get_next_line.h"

int count = 0;

int ft_strchr(char *str, char c, int *len)
{
    *len = 0;
    while(str[*len])
    {
        if (str[(*len)++] == c)
            return *len;
    }
    if(str[*len] != c)
        return -1;
    return *len;
}

char *ft_strjoin(char *s1, char *s2)
{
    size_t len1, len2;
    char *result;

    if (!s1 || !s2)
        return NULL;

    len1 = strlen(s1);
    len2 = strlen(s2);

    result = malloc(len1 + len2 + 1); // No need for sizeof(char), it’s always 1.
    if (!result)
        return NULL;

    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2);
    result[len1 + len2] = '\0';

    free(s1);
    free(s2);

    return result;
}

char *ft_strdup(char *str, int start, int length)
{
    char *result = malloc((length + 1) * sizeof(char)); // Correct allocation.
    if (result == NULL)
        return NULL;

    for (int i = 0; i < length; i++)
    {
        result[i] = str[start + i];
    }

    result[length] = '\0'; // Null-terminate the string.
    return result;
}

char *ft_split(char **str, int position)
{
    if (!str || !*str || position < 0) 
        return NULL; // Ensure valid input

    size_t len1 = position;
    size_t len2 = strlen(*str) - len1; // Length of the second part of the string

    // Allocate memory for the first part and copy it
    char *result = ft_strdup(*str, 0, len1);
    if (!result) 
        return NULL; // Check for memory allocation failure

    // Allocate memory for the second part and copy it
    char *final_str = ft_strdup(*str, len1, len2);
    if (!final_str) 
    {
        free(result);
        return NULL; // Ensure proper cleanup on failure
    }

    free(*str); // Free the original string after splitting
    *str = final_str; // Update *str to point to the second part

    return result; // Return the first part
}

char *compute(char **str, int fd)
{
    int len = 0;
    if (ft_strchr(*str, '\n', &len) > 0)
        return (ft_split(str, len));
    char *buff;
    while (1)
    {
        buff = calloc(BUFFER_SIZE + 1, sizeof(char));
        if (read(fd, buff, BUFFER_SIZE) == 0)
        {
            if (((*str)[0] != 0))
                return *str;
            return (free(buff), NULL);
        }
        *str = ft_strjoin(*str, buff);
        if(ft_strchr(*str, '\n', &len) > 0)
            return (ft_split(str, len));
    }
}

char *get_next_line(int fd)
{
    static char *result[1024] = {0};
    char *str;
    if (fd < 0 || fd > 1024)
    {
        // printf("in if\n");
        return NULL;
    }  
    if (result[fd] == 0)
    {
        result[fd] = calloc(BUFFER_SIZE + 1, sizeof(char));
        if(read(fd, result[fd], BUFFER_SIZE) < 1)
        {
            free(result[fd]);
            result[fd] = NULL;
            return NULL;
        }
    }
    str = compute(&result[fd], fd);
    if (str == 0)
    {
        if(result[fd] != NULL)
        {
            free(result[fd]);
            result[fd] = NULL;
        }
        return NULL;
    }
    return str;
}

// # define CON 6

// int main()
// {
//     int fd = open("empty", O_RDONLY);
//     char arr[CON + 1] = {0};
//     fd = 1000;
//     printf("read returned %ld, the string is: %s and fd is: %d and \n", read(fd, arr, CON), arr, fd);
//     printf("the str is: %s and fd is: %d\n", get_next_line(fd), fd);
// }