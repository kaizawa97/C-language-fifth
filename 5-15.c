#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void my_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reoreder);
int numcmp(const char *, const char *);

int strcapcmp(char *s1, char *s2); //大文字小文字の処理

int main(int argc, char **argv)
{
	int nlines;
	int numeric = 0;
	int reverse = 0;
	int capital = 0;

	while (--argc > 0)
	{
		++argv;
		if (strcmp(*argv, "-n") == 0)
		{
			numeric = 1;
		}
		if (strcmp(*argv, "-r") == 0)
		{
			reverse = 1;
		}
		if (strcmp(*argv, "-f") == 0)
		{
			capital = 1;
		}
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		my_qsort((void **)lineptr, 0, nlines - 1,
				 (int (*)(void *, void *))(numeric ? numcmp : (capital ? strcapcmp : strcmp)), reverse ? -1 : 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}

	return 0;
}


void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *), int reorder)
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
	{
		return;
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
	{
		if (reorder * (*comp)(v[i], v[left]) < 0)
		{
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	my_qsort(v, left, last - 1, comp, reorder);
	my_qsort(v, last + 1, right, comp, reorder);
}

int numcmp(const char *s1, const char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
	{
		return -1;
	}
	else if (v1 > v2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int strcapcmp(char *x, char *y)
{
	 for (; toupper(*x) == toupper(*y); x++, y++)
	 {
		 if (*x == '\0')
		 {
			 return 0;
		 }
	 }
	 return toupper(*x) - toupper(*y);
}
void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define MAXLEN 1000

int my_getline(char s[], int lim);

int my_getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while ((--lim > 0) && (c = getchar()) != EOF && (c != '\n'))
	{
		s[i++] = c;
	}
	if (c == '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = my_getline(line, MAXLEN)) > 0)
	{
		if (nlines >= maxlines || (p = (char *)malloc(len)) == NULL)
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

void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
	{
		printf("%s\n", lineptr[i]);
	}
}
