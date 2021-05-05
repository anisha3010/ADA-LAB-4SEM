#include <stdio.h>
#include <stdlib.h>
 
void tower(int n, char from,
                    char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c \n",from,to);
        return;
    }
    tower(n - 1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c \n",n,from,to);
    tower(n - 1, aux, to, from);
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
int main()
{
    int n,n1,n2,ch;
    do
    {
		printf("1- Perform tower of hanoi\n2-Find GCD of two nos\n3-Exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the number of discs\n");
			scanf("%d",&n);
			printf("INFORMATION: Discs are to be moved from Rod A to Rod C; Rod B is the auxillary rod.\nIMPORTANT: Only one disc can be moved at a time(the uppermost disc) and no disc\nmay be placed on a smaller disc\n");
			tower(n, 'A', 'C', 'B'); // A, B and C are names of rods
			break;
			
			case 2:
			printf("Enter the two nos\n");
			scanf("%d%d",&n1,&n2);
			printf("GCD of %d and %d is %d\n",n1,n2,gcd(n1,n2));
			break;
			
			case 3:
			break;
			
			default:
			printf("Wrong option!\n");
			break;
		}
	}while(ch!=3);
    return 0;
}
