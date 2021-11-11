#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	FILE* in = fopen("access_log_Jul95.txt", "r");
	FILE* out = fopen("0.txt", "w");
	int par, head = 0, tail = 0, m = 0, max = 0, sum = 0, output[2];
	scanf("%d", &par);
	int* steck = malloc(sizeof(int) * (par + 2));
	int* steck2 = malloc(sizeof(int) * (par + 2));
	int mu[] = { 24 * 60 * 60, 0, 60 * 60, 60, 1 };
	char strl[300];
	while (fgets(strl, 300, in) != NULL)
	{
		int i = 0, time = 0, pr = 0, t = 0, k = 0, ind = 0;
		while (strl[i] != '\0')
		{
			if (strl[i] == ' ')
			{
				pr++;
			}
			if (pr == 3)
			{
				if (strl[i] >= '0' && strl[i] <= '9')
				{
					if (strl[i - 1] < '0' || strl[i - 1] > '9')
					{
						k++;
					}
					t = t * 10 + strl[i] - 48;
				}
				else
				{
					time += t * mu[k - 1];
					t = 0;
				}
			}
			if (strl[i] == '\"')
			{
				ind = i;
			}
			i++;
		}
		if (strl[ind + 2] == '5')
		{
			sum = sum + 1;
			fprintf(out, "%s", strl);
		}
		time += t;
		if (time == 0)
		{
			continue;
		}
		if (tail != head && steck[(tail - 1 + par + 2) % (par + 2)] == time)
		{
			steck2[(tail - 1 + par + 2) % (par + 2)]++;
		}
		else
		{
			steck[tail] = time;
			steck2[tail] = 1;
			tail++;
			tail %= (par + 2);
		}
		m++;
		while (head != (tail - 1 + par + 2) % (par + 2))
		{
			if (steck[(tail - 1 + par + 2) % (par + 2)] - steck[head] > par)
			{
				m -= steck2[head];
				head++;
				head %= (par + 2);
			}
			else
			{
				break;
			}
		}
		if (max < m)
		{
			max = m;
			output[0] = steck[head];
			output[1] = steck[(tail - 1 + par + 2) % (par + 2)];
		}
	}
	fprintf(out, "\n%d", sum);
	printf("%d\n", max);
	printf("%d -- %d", output[0], output[1]);
	free(steck);
	free(steck2);
	return 0;
}