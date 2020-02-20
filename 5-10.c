#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// mainの変数群
#define MAXOP 100
#define NUMBER '0'

int getop(char *s);
void push(double);
double pop(void);

//push/popの変数群
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];


int main (int argc, char *argv[])
{
	int type;
	double op2;
	while ((--argc > 0))
	{
		switch (type = getop(*++argv))
		{
		case NUMBER:
			push(atof(*argv));
			break;
		case '+':
			push(pop() + pop());
			break;
		case 'x':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
			{
				push(pop() / op2);
			}
			else
			{
				printf("error: zero divisor\n");
			}
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
			{
				int opopfrom = pop();
				int opopto = op2;
				push(opopfrom % opopto);
			}
			else
			{
				printf("error: zero divisor\n");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %c\n", type);
			break;
		}
	}
		printf("%f\n",pop());
	return 0;
}

//pushとpopの部分の構成
void push(double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

//次の演算子あるいは数値の日演算数をとってくる
int getop(char *s)
{
	char c;
	if (isdigit(c = s[0]))
	{
		return NUMBER;
	}
	else 
	{
		return c;
	}
}
