#include <iostream>
#include <stdio.h>
using  namespace  std;
int main()
{
	int N;
	bool lastLetter = true;

	FILE* in;
	fopen_s(&in, "in.txt", "rt");
	fscanf_s(in, "%d", &N);
	fclose(in);

	FILE* out;
	fopen_s(&out, "out.txt", "w");

	for (int i = 2; i <= N; i++)
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
			if (lastLetter)
			{
				cout << i;
				lastLetter = false;
				fprintf_s(out, "%d", i);
			}
			else
			{
				cout << ", " << i;
				fprintf_s(out, ", %d", i);
			}
		}
	}
	fclose(out);
}