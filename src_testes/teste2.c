
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"

static int	ft_size_matrix(char *str, char c_to_count, char delimiter)
{
	int	index;
    int	is_limiter;
    int	is_character_to_count;

    is_character_to_count = 0;
    is_limiter = 0;
    index = 0;
    while (str[index] != '\0')
    {
        if (str[index] == delimiter)
            is_limiter++;
        if (is_limiter % 2 == 0)
            if (str[index] == c_to_count)
                is_character_to_count++;
        index++;
    }
    return (is_character_to_count);
}

int	ft_strlen_ch(char *str, char stop_if, char ignore_if)
{
    int i;
    int ignore;

    ignore = 1;
    i = 0;
    while (str[i] == ' ')
        i++;
    while (str[i] != '\0')
    {
        if (str[i] == ignore_if)
        {
            i++;
            ignore++;
        }
        if (ignore % 2 == 0)            
            if (str[i] == ignore_if)
                ignore++;
        if (ignore % 2 != 0)
            if (str[i] == stop_if)
                return (++i);
        i++;
    }
    return (i);
}

int main(int argc, char *argv[])
{
    char    *exemplo = "comando1 -flag1     'argumento composto1' -flag2 'argumento composto2' -flag3 'argumento composto3'";
    int i;
    int last_pointer;
    char *temp;

    i = 1;
    last_pointer = 0;
    while (i != 0)
    {
        i = ft_strlen_ch(&exemplo[last_pointer], ' ', '\'');
        temp = calloc(sizeof(char *), i);
        strncpy(temp, &exemplo[last_pointer], i);
        printf("%s\n", temp);
        free(temp);
        //printf("\n%d\n%s", i, &exemplo[last_pointer]);
        //write(1, &exemplo[last_pointer], i);
        //printf(" - > [%d]\n", i);
        last_pointer += i;
    }
}