#include <iostream>
using namespace std;
void fun(int &a,int &b)
{
	int c;
	c=b/10+a/10*10+b%10*100+a%10*1000;
	cout<<"�ϲ������Ϊ"<<c<<endl;

}
int main(){
	int n,m;
	cout<<"����������11~99֮�������";
	cin>>n>>m;
	fun(n,m);
}


