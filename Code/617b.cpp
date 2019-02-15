#include<bits/stdc++.h>
using namespace std;
long long int n,ans=1,y,x;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a==1){
			if(y>0)	ans=ans*(i-x);
			x=i;
			y=1;
		}
	}
	if(y==0)	cout<<"0";
	else cout<<ans;
}