#include "stdio.h"
int fun(int a,int b)
{int c=0;
int a10,a1,b10,b1;
a10=a/10;
a1=a%10;
b10 = b/10;
b1 = b%10;
c = b10+a10*10+b1*100+a1*1000;
return c;
}

void main()
{int a,b,c;
scanf("%d%d",&a,&b);
c=fun(a,b);
printf("%d",c);
}