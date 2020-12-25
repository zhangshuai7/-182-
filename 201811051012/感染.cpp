#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
void main()
{
	int M,N,T;//M,N,T分别表示行列数和周期
	cout<<"请输入矩阵维度及周期："<<endl;
	cin>>M>>N>>T;
    char a[50][50];
    cout<<"请输入矩阵地图"<<endl;
    for(int i=0;i<N;i++)//循环输入
	{
		for(int j=0;j<M;j++)
		{
			cin>>a[i][j];
		}
	}
    for(int f=0;f<T;f++)//检测周期不为零进入感染循环
{
	for(int k=0;k<N;k++)
	{
		for(int l=0;l<M;l++)
		{
			if(a[k][l]=='X')a[k][l]='B';//先将检测到的感染者替换为B，以免后续检测误判
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(a[i][j]=='B')//感染部分
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
	cout<<"感染后的矩阵地图:"<<endl;
 for(int p=0;p<N;p++)
	{
		for(int q=0;q<M;q++)
		{
			cout<<a[p][q];
		}
		cout<<endl;
	}
}