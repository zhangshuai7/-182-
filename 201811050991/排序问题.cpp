#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct Stu 
{
	int id,yuwen,shuxue,yingyu,sum;
}stu[305];
bool cmp(struct Stu a, struct Stu b) 
{
	if(a.sum != b.sum) 
	{
		return a.sum > b.sum;
	} else 
	{
		if(a.yuwen != b.yuwen) 
		{
			return a.yuwen > b.yuwen;
		} else 
		{
			return a.id < b.id;
		}
	}
}
int main() 
{
	int x, y;
	scanf("%d", &y);
	for(x = 0; x < y; ++x) 
	{
		stu[x].id = x+1;
		scanf("%d %d %d", &stu[x].yuwen, &stu[x].shuxue, &stu[x].yingyu);
		stu[x].sum = stu[x].yuwen + stu[x].shuxue + stu[x].yingyu;
	}
	sort(stu, stu+y, cmp);
	printf("Êä³öÎª:");
	for(x = 0; x < 5; ++x) 
	{
		printf("%d %d\n", stu[x].id, stu[x].sum);
	}
	return 0;
}