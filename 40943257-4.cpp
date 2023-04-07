#include<stdio.h>
#include<stdlib.h> 

int main()
{
	int a[6], b;
	for(int i = 1; i <= 100; i++)
	{
		do{
			a[0] = rand()  % 9 + 1;
			a[1] = rand()  % 9 + 1;
			a[2] = rand()  % 9 + 1;
			a[3] = rand()  % 9 + 1;
		}while((a[0] == a[1]) || (a[2] == a[3]));
		b = rand()  % 4;
		printf("(%d) %d/%d", i, a[0], a[1]);
		switch(b)
		{
			case 0 : printf(" + %d/%d = ", a[2], a[3]);
					 a[5] = a[1] * a[3];
				     a[4] = a[0] * a[3] + a[2] * a[1]; break;
			case 1 : printf(" - %d/%d = ", a[2], a[3]);
					 a[5] = a[1] * a[3];
				     a[4] = a[0] * a[3] - a[2] * a[1]; break;
			case 2 : printf(" * %d/%d = ", a[2], a[3]);
					 a[5] = a[1] * a[3];
				     a[4] = a[0] * a[2];               break;
			case 3 : printf(" / %d/%d = ", a[2], a[3]); 
					 a[5] = a[1] * a[2];
				     a[4] = a[0] * a[3];
		}
		int c = 0;
		if(a[4] < 0)
		{
			a[4] = - a[4]; 
			c = 1;
		}
		for(int j = (a[4] + a[5]) / 2; j >= 1; j--)
			if((a[4] % j == 0) && (a[5] % j == 0))
			{
				a[4] /= j;
				a[5] /= j;
				break; 
			}
		if(c)
			a[4] = - a[4];
		if((a[5] == 1) || (a[4] == 0))
			printf("%d", a[4]);
		else
			printf("%d/%d", a[4], a[5]);
		if(i % 2 == 0)
			printf("\n\n");
		else
			printf("\t\t");
	}
	return 0;
}
