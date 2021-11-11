#include<stdio.h>
const int EF = 1000000000;
struct f {
	int a[];
};
void p(struct f* x, struct f* y, int n)
{
	int b = 0, c, d;
	for (int i = 0; i <= n; i++)
	{
		x->a[i] = (x->a[i] + y->a[i] + b) % EF;
		b = (x->a[i] + y->a[i] + b) / EF;
		c = EF;
		d = x->a[i];
		for (int j = 0; j < 10; j++)
		{
			printf("%d",  d/c);
			d = d % c;
			c = c / 10;
		}
	}
}
void m(struct f* x, struct f* y, int n)
{
	int b = 0, c, d;
	for (int i = 0; i <= n; i++)
	{
		x->a[i] = (x->a[i] + y->a[i] + b) % EF;
		b = (x->a[i] + y->a[i] + b) / EF;
		c = EF;
		d = x->a[i];
		for (int j = 0; j < 10; j++)
		{
			printf("%d", d / c);
			d = d % c;
			c = c / 10;
		}
	}
}
struct f* mu1(struct f* x, int a)
{
	struct f* y = malloc(sizeof(struct f) + 150);
	for (int i = 1; i <= a; i++)
	{
		y = pl(y, x);
	}
}
int main()
{
	struct f* s1 = malloc(sizeof(struct f) + 128);
	for (int i = 0; i <= 2; i++)
	{
		s1->a[i] = 5 - i;
	}
	p(s1, s1, 2);
	printf("\n");
	for (int i = 0; i <= 2; i++)
	{
		printf("%d", s1->a[i]);
	}
	return 0;
}