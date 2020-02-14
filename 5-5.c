#include <stdio.h>

void strncpy01(char *s, char *t, int number);
void strcat01(char *s, char *t, int number);
int strcmp01(char *s, char *t, int number);

int main()
{
	char s[1024];
	char *input = "abcd";

	char be[128] = "abcdef";
	char af[128] = "ghijkl";
	
	char cm1[128] = "abcd";
	char cm2[128] = "abdd";

	strncpy01(s, input, 3);
	strcat01(be, af,3);
	printf("%s\n", s);
	printf("%s\n", be);
	printf("%d\n", strcmp01(cm1,cm2,3));
}

void strncpy01(char *s, char *t, int number)
{
	int i;
	for (i = 0; i < number; ++i)
	{
		*s++ = *t++;
	}
}

void strcat01(char *s, char *t, int number)
{
	while (*s++)
		;
	s--;
	for ( int i = 0; i < number; ++i)
	{
		*s++ = *t++;
	}
}

int strcmp01(char *s, char *t, int number)
{
	for(int i = 0; i < number; ++i)
	{
		for(; *s == *t; s++, t++)
		{
			if (*s == '\0')
			{
				return 0;
			}
		}
	}
	return *s - *t;
}

