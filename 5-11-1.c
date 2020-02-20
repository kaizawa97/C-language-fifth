#include <stdio.h>

int main(int argc, char *argv[])
{
	char c, i, inttype, number;
	int count, a;

	count = 0;

	if (argc == 1)
	{
		number = 4;
	}
	else
	{
		inttype = (*++argv)[0];
		number = inttype - '0';
	}

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			++count;
		}
		else
		{
			for (a = 0; a < count; ++a)
			{
				putchar(' ');
			}
			putchar(c);
			count = 0;
		}
		if (count == number)
		{
			i = '\t';
			putchar(i);
			count = 0;
		}
	}
}
