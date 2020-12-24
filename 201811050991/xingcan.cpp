#include <iostream>
using namespace std;
void func(int &a,int &b)
{
	int c;
	c=b/10+a/10*10+b%10*100+a%10*1000;
	cout<<"这个合并数是："<<c<<endl;

}
void main(){
	int m,n;
	cout<<"请输入两个两位数：";
	cin>>m>>n;
	func(m,n);
}