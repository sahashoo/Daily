#include<bits/stdc++.h>
using namespace std;
int n,c;

int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}

int gcd(int a,int b){
	return(b?gcd(b,a%b):a);
}

int lcm(a,b){
	return a*b/gcd(a,b);
}

int main(){
	cin>>n>>c;
	cout<<gcd(n,c)<<" "<<lcm(a,b);
}