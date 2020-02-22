#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define MAXLINE 1000
#define ALLOCSIZE 10000

char *alloc(int);
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int writenumber);
int getline01(char*, int);

int main(int argc, char *argv[])
{
	int nlines, inttype, number;

	if ((*++argv)[0]  == '-')
	{
		if ((*argv)[1] == 'n')
		{
			number = atoi(*(++argv));
		}
		else
		{
			printf("Bad Option\n");
			return 0;
		}
	}

	if(number <= 0)
	{
		printf("Bad Number\n");
		return 0;
	}

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		writelines(lineptr, nlines,number);
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = getline01(line, MAXLINE)) > 0)
	{
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
		{
			return -1;
		}
		else
		{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
		return nlines;
}
void writelines(char *lineptr[], int nlines, int writenumber)
{
	int i;

	if (writenumber > nlines)
	{
		writenumber = nlines;
	}

	for (i = nlines - writenumber; i < nlines ; i++)
	{
		printf("%s\n", lineptr[i]);
	}
}

int getline01(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		s[i] = c;
	}
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n;
	}
	else
	{
		return 0;
	}
}
