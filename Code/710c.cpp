#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	int n;cin>>n;
	int k=n/2,a[]={1,2};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int id=min(abs(i-k),abs(j-k))%2;
			cout<<a[id]<<" ";
			a[id]+=2;
		}
		cout<<'\n';
	}
}