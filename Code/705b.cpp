#include<bits/stdc++.h>
using namespace std;
int temp,n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		temp=(temp+k-1)%2;
		if(temp)cout<<1<<endl;
		else cout<<2<<endl;
	}
}