#include<bits/stdc++.h>
using namespace std;
int n,k,y=(int)1e9;

int main(){
	cin>>n>>k;
	if(n*(n-1)/2<=k)return cout<<"no solution",0;
	for(int i=0;i<n;i++){
		if(i%2==0)cout<<i<<" "<<y<<endl;
		else cout<<i<<" "<<-y<<endl,y-=n;
	}
}