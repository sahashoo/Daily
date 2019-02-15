///age yakam bekeshi beham is no problem._.
#include<bits/stdc++.h>
using namespace std;
int a,b,res;

int main(){
	cin>>a>>b;
	if(a==b)return cout<<"infinity",0;
	if(a<b)return cout<<0,0;
	a-=b;//cout<<a<<endl;
	for(int i=1;i*i<=a;i++){
		if(a%i==0){
			if(i>b)res++;
			if(a/i>b&&i*i!=a)res++;
		}
	}
	cout<<res;
}