#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

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
            return NULL;
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
        return NULL;
    if (result[5] == 0)
    {
        result[5] = calloc(BUFFER_SIZE + 1, sizeof(char));
        read(fd, result[5], BUFFER_SIZE);
    }
    str = compute(&result[5], fd);
    if (str == 0)
        return NULL;
    return str;
}

int main()
{
    // int len = 0;
    // printf("strchr returned: %d\n", ft_strchr("helloniggaworld", 'w', &len));
    // char *str = ft_strdup("khalid", 1, 3);
    // printf("strdup returned: %s\n", str);
    // print("ayoooo\n");
    // test split
    // char *str = strdup("khalidwa3r");
    // char *result = ft_split(&str, 4);
    // printf("str is: %s\n", str);
    // printf("result is: %s\n", result);
    int fd = open("test.txt", O_RDONLY);
    char *str = get_next_line(fd);
    printf("the return is: %s\n", str);
    str = get_next_line(fd);
    printf("the return is: %s\n", str);
    str = get_next_line(fd);
    printf("the return is: %s\n", str);
    str = get_next_line(fd);
    printf("the return is: %s\n", str);
    str = get_next_line(fd);
    printf("the return is: %s\n", str);
    str = get_next_line(fd);
    printf("the return is: %s\n", str);
    str = get_next_line(fd);
    printf("the return is: %s\n", str);
    str = get_next_line(fd);
    printf("the return is: %s\n", str);
    str = get_next_line(fd);
    printf("the return is: %s\n", str);
}
