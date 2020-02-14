#include <stdio.h>

int strend (char *s,char *t);
int strlen(char *s);

int main ()
{
	int number;
	char *x = "abcd";
	char *y = "cd";
	number = strend(x,y);
	printf("%d",number);
}

int strend (char *s,char *t)
{
	int x,y;
	x = strlen(s);
	y = strlen(t);

	if (y > x)
	{
		return 0;
	}
	else
	{
		for(int i = 0; i < y; ++i) 
		{
			if (*(s + x - i - 1) != *(t + y - i -1))
			{
				return 0;
			}
		}
		return 1;
	}
}

int strlen(char *s)
{
	char *p = s;

	while (*p != '\0')
	{
		p++;
	}
	return p - s;
}
