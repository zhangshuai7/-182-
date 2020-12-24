#include<iostream>
using namespace std;
int fun(int N, int M)
{
	int i;
	int monkey[100];
	for (i = 0; i < N; i++)
		monkey[i] = 1;     //猴子状态初始化，为1表示可能被选上；
	int sum = 0,     //循环记数；
		count = N;   //累积记数初始化，大于1表明还有大王候选人；
	while (count > 1)
	{
		count = 0;
		for (i = 0; i <N; i++)
		{
			sum += monkey[i];
			if (sum == M)
				sum = monkey[i] = 0;  //淘汰猴子；
			count += monkey[i];
		}
	}
	for (i = 0; i <N; i++)
		if (monkey[i] != 0)
			return i;   //找到猴子大王编号（从0开始的）；
}
int main()
{
	int m,n;
	cout << "please enter the number of monkey: ";
	cin >> m;
	cout << "please enter the count number: ";
	cin	>> n;
	cout << "the" << fun(m, n) + 1 << "monkey is the king" << endl;
}
