#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
void main()
{
	int m,n,T;
	//m,n,T�ֱ��ʾ������������
	cout<<"����������С��м����ڣ��ո��������"<<endl;
	cin>>m>>n>>T;
    char a[50][50];
    cout<<"����������ͼ"<<endl;
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
    for(int f=0;f<T;f++)//�����ڲ�Ϊ������Ⱦѭ��
{
	for(int k=0;k<n;k++)
	{
		for(int l=0;l<m;l++)
		{
			if(a[k][l]=='X')a[k][l]='S';//����⵽�ĸ�Ⱦ���滻ΪS�Ա�֤��������ж�
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='S')//��Ⱦ����
			{
				a[i][j]='X';
			  if(a[i][j-1]=='O')a[i][j-1]='X';
			  if(a[i][j+1]=='O')a[i][j+1]='X';
			  if(a[i+1][j]=='O')a[i+1][j]='X';
			  if(a[i-1][j]=='O')a[i-1][j]='X';
			}

		}
	}
	}
	cout<<"��Ⱦ�������ֲ���ͼΪ:"<<endl;
 for(int C=0;C<n;C++)
	{
		for(int D=0;D<m;D++)
		{
			cout<<a[C][D];
		}
		cout<<endl;
	}
}