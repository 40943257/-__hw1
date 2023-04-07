#include <stdio.h>
#include <stdlib.h>

// 輾轉相除法
int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main()
{
	// num1是第一個分數 num2是第二個分數 num3是運算後的結果 operatorNumber是運算符號
	int num1[2], num2[2], num3[2], operatorNumber;

	// 題目要求執行100次
	for (int i = 1; i <= 100; i++)
	{
		// 隨機選出兩組分母分子不同的分數
		do
		{
			num1[0] = rand() % 9 + 1;
			num1[1] = rand() % 9 + 1;
			num2[0] = rand() % 9 + 1;
			num2[1] = rand() % 9 + 1;
		} while ((num1[0] == num1[1]) || (num2[0] == num2[1]));

		// 隨機選一個願算符號
		// 0是+
		// 1是-
		// 2是*
		// 3是/
		operatorNumber = rand() % 4;

		// 印出第一個分數
		printf("(%d) %d/%d", i, num1[0], num1[1]);

		// 判斷是哪個運算符號、執行運算印出運算符號和第二個分數
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

		// 紀錄結果是不是負數 因為在做最大公因數時 會影響結果
		bool isNegativeNumber = false;
		if (num3[0] < 0)
		{
			num3[0] = -num3[0];
			isNegativeNumber = true;
		}

		// 找出最大公因數 並化簡
		int commonFactor = GCD(num3[0], num3[1]);
		num3[0] /= commonFactor;
		num3[1] /= commonFactor;

		// 便回負數
		if (isNegativeNumber)
			num3[0] = -num3[0];

		// 如果分子是0 或分母是1 只要印出分子就好
		if ((num3[1] == 1) || (num3[0] == 0))
			printf("%d", num3[0]);
		else
			printf("%d/%d", num3[0], num3[1]);

		// 排版
		if (i % 2 == 0)
			printf("\n\n");
		else
			printf("\t\t");
	}
	return 0;
}
