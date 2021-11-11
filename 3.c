#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
struct a {
	int time;
	char st[300];
};
void merge(struct a a[], int l, int m, int r)
{
	struct a L[1000], R[1000];
	for (int i = 1; i <= (m - l + 1); i++)
	{
		L[i] = a[l + i - 1];
	}
	for (int i = 1; i <= (r - m); i++)
	{
		R[i] = a[m + i];
	}
	L[m - l + 2].time = 1000000000;
	R[r - m + 1].time = 1000000000;
	int i = 1, j = 1;
	for (int k = l; k <= r; k++)
	{
		if (L[i].time < R[j].time)
		{
			a[k] = L[i];
			i = i + 1;
		}
		else
		{
			a[k] = R[j];
			j = j + 1;
		}
	}
}
void sort(struct a a[], int l, int r)
{
	if (l < r)
	{
		sort(a, l, (l + r) / 2);
		sort(a, (l + r) / 2 + 1, r);
	}
	merge(a, l, (l + r) / 2, r);
}
int main()
{
	FILE* f;
	FILE* w;
	w = fopen("0.txt", "w");
	f = fopen("access_log_Jul95.txt", "r");
	int b[6] = { 24 * 60 * 60,0,60 * 60,60,1 };
	struct a a[1000];
	int j = 0, s = 0;
	while (fgets(a[j].st, 300, f) != NULL)
	{
		int i = 0, pr = 0, c = 0, d = 0, e = 0;
		while (a[j].st[i] != '\0')
		{
			if (a[j].st[i] == ' ')
			{
				pr += 1;
			}
			if (pr == 3)
			{
				if (a[j].st[i] >= 48 && a[j].st[i] <= 57)
				{
					if (a[j].st[i - 1] < 48 || a[j].st[i - 1] >57)
					{
						e += 1;
					}
					c = c * 10 + a[j].st[i] - 48;
				}
				else
				{
					d = d + c * b[e - 1];
					c = 0;
				}
			}
			if (pr == 4)
			{
				d += c;
				c = 0;
			}
			if (a[j].st[i] == '\"')
			{
				c = i;
			}
			i += 1;
		}
		a[j].time = d;
		if (a[j].st[c+2] == '5')
		{
			fprintf(w, "%s", a[j].st);
		}
		j++;
		if (j == 1000)
		{
			j = 0;
		}
		s = s + 1;
	}
	sort(a, 0, j - 1);
	printf("%d\n", j);
	for (int i = 0; i < j; i++)
	{
		printf("%d %s", i, a[i].st);
	}
	printf("%d", s - 1);
	return 0;
}