#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=107;
int n,arr[maxn],sum=10,cnt,ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n&&sum+arr[i]<=720;i++){
		cnt++;
		sum+=arr[i];
		if(sum>360)ans+=sum-360;
	}
	cout<<cnt<<" "<<ans;
}
