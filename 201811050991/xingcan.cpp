#include <iostream>
using namespace std;
void func(int &a,int &b)
{
	int c;
	c=b/10+a/10*10+b%10*100+a%10*1000;
	cout<<"����ϲ����ǣ�"<<c<<endl;

}
void main(){
	int m,n;
	cout<<"������������λ����";
	cin>>m>>n;
	func(m,n);
}