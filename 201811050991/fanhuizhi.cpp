#include"stdio.h"
int fun(int a,int b)
{
int c=0;
int a1,a2,b1,b2;
a1=a/10;
a2=a%10;
b1=b/10;
b2=b%10;
c=b1+a1*10+b2*100+a2*1000;
return c;
}

void main()
{int a,b,c;
scanf("%d%d",&a,&b);
c=fun(a,b);
printf("%d",c);
}