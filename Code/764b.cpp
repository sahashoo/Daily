#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,arr[300000];
int main(){
	cin>>n;
	for(ll i=0;i<n;i++)	cin>>arr[i];
	for(ll i=0;i<n/2;i++){
		if(i%2==0)	swap(arr[i],arr[n-1-i]);
	}
	for(ll i=0;i<n;i++)	cout<<arr[i]<<" ";
}