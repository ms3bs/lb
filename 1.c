#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <locale.h>
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	FILE* f;
	if (argc < 2)
	{
		printf("введите\n");
		printf("1.[option]\n  -l, --lines\n  -c, --bytes\n  -w, --words\n");
		printf("2.filename");
		return 0;
	}
	if ((f = fopen(argv[2], "r")) == NULL)
	{
		printf("такого файла нет");
		return 0;
	}
	int a, b = 0, l = 1, w = 0, c = 0;
	while ((a = fgetc(f)) != EOF)
	{
		if (a == '\n')
		{
			l += 1;
		}
		if (a == ' ' || a == '\n' || a=='\t')
		{
			b = 0;
		}
		else
		{
			if (b == 0)
			{
				w += 1;
			}
			b = 1;
		}
		c += 1;
	}
	if (strcmp(argv[1], "[-l]") + strcmp(argv[1], "[--linies]") == 1)
	{
		if (c == 0)
		{
			printf("0");
		}
		else
		{
			printf("%d", l);
		}
		return 0;
	}
	if (strcmp(argv[1], "[-c]") + strcmp(argv[1], "[--bytes]") == 1)
	{
		printf("%d", c);
		return 0;
	}
	if (strcmp(argv[1], "[-w]") + strcmp(argv[1], "[--words]") == 1)
	{
		printf("%d", w);
		return 0;
	}
	printf("такой функции нет\n");
	printf("1.option\n  -l, --lines\n  -c, --bytes\n  -w, --words\n");
	fclose(f);
	return 0;
}