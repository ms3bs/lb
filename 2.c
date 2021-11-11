#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
const int EF = 1000000000;
const int k = 35;
struct uint1024_t {
	int a[];
};
void scanf_value(struct uint1024_t* x)
{
	char a[1000];
	int i = 1, n, b, c, d = k + 1;
	scanf("%c", &a[i]);
	while (a[i] != '\n')
	{
		i += 1;
		scanf("%c", &a[i]);
	}
	n = i - 1;
	for (int i = 1; i <= k; i++)
	{
		x->a[i] = 0;
	}
	for (i = n; i >= 1; i--)
	{
		if ((n - i) % 9 == 0)
		{
			c = 1;
			d = d - 1;
		}
		b = a[i] - 48;
		x->a[d] += b * c;
		c *= 10;
	}
}
void pintf_value(struct uint1024_t* x)
{
	int d, c, b = 0;
	for (int i = 1; i <= k; i++)
	{
		d = x->a[i];
		c = EF / 10;
		for (int j = 0; j < 9; j++)
		{
			if (d / c != 0 || b == 1)
			{
				printf("%d", d / c);
				b = 1;
			}
			d = d % c;
			c = c / 10;
		}
	}
}
struct uint1024_t* from_uint(unsigned int y)
{
	struct uint1024_t* x = malloc(sizeof(struct uint1024_t) + 140);
	x->a[k] = y % EF;
	x->a[k - 1] = y / EF;
	for (int i = 1; i < k - 1; i++)
	{
		x->a[i] = 0;
	}
	return x;
}
struct uint1024_t* add_op(struct uint1024_t* x, struct uint1024_t* y)
{
	struct uint1024_t* z = malloc(sizeof(struct uint1024_t) + 140);
	int b = 0;
	for (int i = k; i >= 1; i--)
	{
		z->a[i] = (x->a[i] + y->a[i] + b) % EF;
		b = (x->a[i] + y->a[i] + b) / EF;
	}
	return z;
}
struct uint1024_t* subtr_op(struct uint1024_t* x, struct uint1024_t* y)
{
	struct uint1024_t* z = malloc(sizeof(struct uint1024_t) + 140);
	for (int i = 1; i <= k; i++)
	{
		z->a[i] = 0;
	}
	int b = 0;
	for (int i = k; i >= 1; i--)
	{
		if (x->a[i] - y->a[i] - b < 0)
		{
			z->a[i] = EF + x->a[i] - y->a[i] - b;
			b = 1;
		}
		else
		{
			z->a[i] = x->a[i] - y->a[i] - b;
			b = 0;
		}
	}
	return z;

}
struct uint1024_t* mult_op(struct uint1024_t* x, struct uint1024_t* y)
{
	struct uint1024_t* z = malloc(sizeof(struct uint1024_t) + 140);
	for (int i = 1; i <= k; i++)
	{
		z->a[i] = 0;
	}
	int c, c2, b = 0, d, d2;
	for (int i = k; i >= 1; i--)
	{
		c = x->a[i];
		for (int j = 1; j < 10; j++)
		{
			for (int i2 = k; i2 >= 1; i2--)
			{
				c2 = y->a[i2];
				for (int j2 = 1; j2 < 10; j2++)
				{
					d = 1;
					for (int x = 1; x <= (j + j2 - 2) % 9; x++)
					{
						d = d * 10;
					}
					if (k - (k - i) - (k - i2) - (j + j2 - 2) / 9 - 1 < 0)
					{
						continue;
					}
					z->a[k - (k - i) - (k - i2) - (j + j2 - 2) / 9] += (c % 10 * (c2 % 10) + b) % 10 * d;
					b = (c % 10 * (c2 % 10) + b) / 10;
					z->a[k - (k - i) - (k - i2) - (j + j2 - 2) / 9 - 1] += z->a[k - (k - i) - (k - i2) - (j + j2 - 2) / 9] / EF;
					z->a[k - (k - i) - (k - i2) - (j + j2 - 2) / 9] %= EF;
					c2 = c2 / 10;
				}
			}
			c = c / 10;
		}
	}
	return z;
}
int main()
{
	struct uint1024_t* x = malloc(sizeof(struct uint1024_t) + 140);
	struct uint1024_t* y = malloc(sizeof(struct uint1024_t) + 140);
	struct uint1024_t* z = malloc(sizeof(struct uint1024_t) + 140);
	scanf_value(x);
	scanf_value(y);
	z = mult_op(x, y);
	pintf_value(z);
	printf("\n");
	z = add_op(x, y);
	pintf_value(z);
	printf("\n");
	free(x);
	free(y);
	free(z);
	return 0;
}