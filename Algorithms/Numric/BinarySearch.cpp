#include<bits/stdc++.h>
using namespace std;
int arr[110000],n;

bool check(int a){
	if(arr[a]>=k)return true;
	return false
}

int BS(int l,int r){
	while(r-l>1){
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	return r;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	int k=-1;
	cin>>k;
	cout<<bs(1,n);
}