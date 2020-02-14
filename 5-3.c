#include <stdio.h>

void strcat01(char s[], char t[]);
int main ()
{
	char x[128] = "abc";
	char y[128] = "def";
	strcat01(x,y);
	printf("%s\n",x);
}

void strcat01(char *s, char *t)
{
	while (*s++);
	s--;
	while (*s++ = *t++);
}
