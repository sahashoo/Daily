#include<bits/stdc++.h>
using namespace std;
int a,n;

int main(){
	cin>>n>>a;
	if(a%2==0)a=n-a+1;
	cout<<a/2+1;
}