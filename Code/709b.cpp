#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int arr[maxn];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,a;cin>>n>>a;
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	if(n==1)return cout<<0,0;
	int tmp=min(abs(arr[0]-a),abs(arr[n-2]-a))+arr[n-2]-arr[0];
	tmp=min(tmp,min(abs(arr[1]-a),abs(arr[n-1]-a))+arr[n-1]-arr[1]);
	cout<<tmp;
}