#include<iostream>
using namespace std;
int fun(int N, int M)
{
	int i;
	int monkey[100];
	for (i = 0; i < N; i++)
		monkey[i] = 1;     //����״̬��ʼ����Ϊ1��ʾ���ܱ�ѡ�ϣ�
	int sum = 0,     //ѭ��������
		count = N;   //�ۻ�������ʼ��������1�������д�����ѡ�ˣ�
	while (count > 1)
	{
		count = 0;
		for (i = 0; i <N; i++)
		{
			sum += monkey[i];
			if (sum == M)
				sum = monkey[i] = 0;  //��̭���ӣ�
			count += monkey[i];
		}
	}
	for (i = 0; i <N; i++)
		if (monkey[i] != 0)
			return i;   //�ҵ����Ӵ�����ţ���0��ʼ�ģ���
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
