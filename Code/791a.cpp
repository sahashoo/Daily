#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	int i=0;
	while(n<=m){n=n*3;m=m*2;i++;}
	cout<<i;
}