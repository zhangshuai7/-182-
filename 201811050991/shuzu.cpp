#include <stdio.h>
#define MaxSize 8
void monkeyking(int m,int n)
{
    int p[MaxSize];
    int i,j,k;
    for (i=0; i<m; i++)         
        p[i]=1;
    k=-1;                       
    printf("其出列的顺序:");
    for (i=1; i<=m; i++)        
    {
        j=1;      
        while(j<=n)  
        {
            k=(k+1)%m;        
            if (p[k]==1) j++;
        }
        p[k]=0;   
        printf("%d ",k+1);      
    }
    printf("\n");
}

int main()
{
    int m,n;
    scanf("%d %d", &m, &n);
    monkeyking(m,n);
    return 0;
}