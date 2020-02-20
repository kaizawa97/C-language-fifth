#include <stdio.h>
void appear(int len, char cap);

int main(int argc, char *argv[])
{
	int c, i, tab, inttype;
	i = 0;

	if (argc == 1)
	{
		tab = 4;
	}
	else
	{
		inttype = (*++argv)[0];
		tab = inttype - '0';
	}

	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			appear(tab - i, ' ');
			i = 0;
		}
		else
		{
			putchar(c);
		}
	}
}

void appear(int len, char cap)
{
	int i;
	for (i = 0; i < len; i++)
	{
		putchar(cap);
	}
}