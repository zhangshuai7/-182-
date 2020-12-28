#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
void main()
{
	int m,n,T;
	//m,n,T分别表示行列数和周期
	cout<<"请输入矩阵行、列及周期（空格隔开）："<<endl;
	cin>>m>>n>>T;
    char a[50][50];
    cout<<"请输入矩阵地图"<<endl;
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
    for(int f=0;f<T;f++)//若周期不为零进入感染循环
{
	for(int k=0;k<n;k++)
	{
		for(int l=0;l<m;l++)
		{
			if(a[k][l]=='X')a[k][l]='S';//将检测到的感染者替换为S以保证后续检测判断
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='S')//感染区域
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
	cout<<"感染后的情况分布地图为:"<<endl;
 for(int C=0;C<n;C++)
	{
		for(int D=0;D<m;D++)
		{
			cout<<a[C][D];
		}
		cout<<endl;
	}
}