#include <iostream>
using namespace std;
void func(int *a,int *b)
{
	int c;
	c=*b/10+*a/10*10+*b%10*100+*a%10*1000;
	cout<<"合并后的数为"<<c<<endl;

}
int main(){
	int n,m;
	cout<<"请输入两个11~99的整数";
	cin>>n>>m;
	func(&n,&m);
}


