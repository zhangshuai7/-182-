#include <iostream>
using namespace std;
void func(int &a,int &b)
{
	int c;
	c=b/10+a/10*10+b%10*100+a%10*1000;
	cout<<"The Consolidated number is"<<c<<endl;

}
void main(){
	int m,n;
	cout<<"Enter two numbers";
	cin>>m>>n;
	func(m,n);
}


