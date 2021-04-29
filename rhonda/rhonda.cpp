#include <iostream>
#include <stdio.h>
using  namespace  std;
int main()
{
	int entNum;
	bool lastDigit = true;

	FILE* in;
	in = fopen("/media/sd0/in.txt", "rt");
	fscanf(in, "%d", &entNum);
	fclose(in);

	FILE* out;
	out = fopen("/media/sd0/out.txt", "w");

	for (int i = 2; i <= entNum; i++)
	{
		bool isPrime = true;
		for (int k = 2; k < i; k++)
		{
			if (i % k == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			if (lastDigit)
			{
				lastDigit = false;
				fprintf(out, "%d", i);
			}
			else
				fprintf(out, ", %d", i);
		}
	}
	fclose(out);
}