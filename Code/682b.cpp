#include<bits/stdc++.h>
using namespace std;
int ans,n,arr[100007];
int main(){
	cin>>n;
	ans++;
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++)if(arr[i]>=ans)ans++;
	cout<<ans;
}