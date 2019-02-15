#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[990000],n,ch;

int main(){
	cin>>n;
	for(ll i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	for(ll i=2;i<n;i++){
		if(arr[i-2]+arr[i-1]>arr[i]){cout<<"YES";return 0;}
	}
	cout<<"NO";
}