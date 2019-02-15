#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y,z;
int main(){
	cin>>a>>x>>b>>y>>c>>z;
	cout<<3<<endl;
	cout<<a+b-c<<" "<<x+y-z<<endl;
	cout<<a-b+c<<" "<<x-y+z<<endl;
	cout<<-a+b+c<<" "<<-x+y+z<<endl;
}