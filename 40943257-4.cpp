#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1[2], num2[2], num3[2], operatorNumber;
	for (int i = 1; i <= 100; i++)
	{
		do
		{
			num1[0] = rand() % 9 + 1;
			num1[1] = rand() % 9 + 1;
			num2[0] = rand() % 9 + 1;
			num2[1] = rand() % 9 + 1;
		} while ((num1[0] == num1[1]) || (num2[0] == num2[1]));
		operatorNumber = rand() % 4;
		printf("(%d) %d/%d", i, num1[0], num1[1]);
		switch (operatorNumber)
		{
		case 0:
			printf(" + %d/%d = ", num2[0], num2[1]);
			num3[1] = num1[1] * num2[1];
			num3[0] = num1[0] * num2[1] + num2[0] * num1[1];
			break;
		case 1:
			printf(" - %d/%d = ", num2[0], num2[1]);
			num3[1] = num1[1] * num2[1];
			num3[0] = num1[0] * num2[1] - num2[0] * num1[1];
			break;
		case 2:
			printf(" * %d/%d = ", num2[0], num2[1]);
			num3[1] = num1[1] * num2[1];
			num3[0] = num1[0] * num2[0];
			break;
		case 3:
			printf(" / %d/%d = ", num2[0], num2[1]);
			num3[1] = num1[1] * num2[0];
			num3[0] = num1[0] * num2[1];
		}
		bool isNegativeNumber = false;
		if (num3[0] < 0)
		{
			num3[0] = -num3[0];
			isNegativeNumber = true;
		}
		for (int j = (num3[0] + num3[1]) / 2; j >= 1; j--)
			if ((num3[0] % j == 0) && (num3[1] % j == 0))
			{
				num3[0] /= j;
				num3[1] /= j;
				break;
			}
		if (isNegativeNumber)
			num3[0] = -num3[0];
		if ((num3[1] == 1) || (num3[0] == 0))
			printf("%d", num3[0]);
		else
			printf("%d/%d", num3[0], num3[1]);
		if (i % 2 == 0)
			printf("\n\n");
		else
			printf("\t\t");
	}
	return 0;
}
