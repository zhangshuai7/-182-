#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
void main()
{
	int M,N,T;//M,N,T�ֱ��ʾ������������
	cout<<"���������ά�ȼ����ڣ�"<<endl;
	cin>>M>>N>>T;
    char a[50][50];
    cout<<"����������ͼ"<<endl;
    for(int i=0;i<N;i++)//ѭ������
	{
		for(int j=0;j<M;j++)
		{
			cin>>a[i][j];
		}
	}
    for(int f=0;f<T;f++)//������ڲ�Ϊ������Ⱦѭ��
{
	for(int k=0;k<N;k++)
	{
		for(int l=0;l<M;l++)
		{
			if(a[k][l]=='X')a[k][l]='B';//�Ƚ���⵽�ĸ�Ⱦ���滻ΪB����������������
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(a[i][j]=='B')//��Ⱦ����
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
	cout<<"��Ⱦ��ľ����ͼ:"<<endl;
 for(int p=0;p<N;p++)
	{
		for(int q=0;q<M;q++)
		{
			cout<<a[p][q];
		}
		cout<<endl;
	}
}