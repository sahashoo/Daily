#include<bits/stdc++.h>
using namespace std;
long long a,b,sum;

int ch(int n){
	if(n==0)return 6;
	if(n==1)return 2;
	if(n==2||n==3||n==5)return 5;
	if(n==4)return 4;
	if(n==9||n==6)return 6;
	if(n==7)return 3;
	if(n==8)return 7;
}

void num(int n){
	if(n==0)return ;
	sum+=ch(n%10);
	num(n/10);
}

int main(){
	cin>>a>>b;
	for(int i=a;i<=b;i++){
		num(i);
	}
	cout<<sum;
}