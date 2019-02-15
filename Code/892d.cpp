///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
pair<int,int>arr[25];
int a[25];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0,x;i<n;i++)cin>>x,arr[i]={x,i};
	sort(arr,arr+n);
	arr[n]=arr[0];
	for(int i=0;i<n;i++)a[arr[i].S]=arr[i+1].F;
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
