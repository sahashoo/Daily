#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100;
int arr[maxn];

int32_t main(){
	int n;cin>>n;
	for(int i=1;i<n;i++)cin>>arr[i];
	int a,b;cin>>a>>b;
	int sum=0;
	for(int i=a;i<b;i++)sum+=arr[i];
	cout<<sum;
}