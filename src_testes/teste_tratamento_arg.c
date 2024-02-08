
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char    *exemplo = "comando1 -flag1 'argumento composto1' -flag2 'argumento composto2'";
	int     last_pointer;
	int     is_aspas;
	int     is_space;
	int     ignore_space;
	int     size;

	size = 0;
	is_space = 0;
	is_aspas = 0;
	last_pointer = 0;
	ignore_space = 0;
	while (exemplo[last_pointer] != '\0')
	{
		if (exemplo[last_pointer] == '\'')
		{
			is_aspas++;
			last_pointer++;
		}
		if (is_aspas % 2 == 0)
		{
			if (exemplo[last_pointer] == ' ')
			{
				printf("\n");
				is_space++;
			}
			else
			   printf("%c", exemplo[last_pointer]); 
		}
		else
		{
			printf("%c", exemplo[last_pointer]);
		}
		last_pointer++;
	}
	printf("\n[%d]\n", is_space); 
}