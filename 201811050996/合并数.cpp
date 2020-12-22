#include "stdio.h"
int fun(int a,int b)
{int c=0;
int n,m,s,l;
n=a/10;
m=a%10;
s=b/10;
l=b%10;
c = s+n*10+l*100+m*1000;
return c;
}

int main()
{int a,b,c;
scanf("%d%d",&a,&b);
c=fun(a,b);
printf("%d",c);
}
