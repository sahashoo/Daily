///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=3e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
priority_queue<pair<int,int> >a;
int x,res[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=0;i<k;i++)cin>>x,a.push({x,i});
	long long sum=0;
	for(int i=k;i<n+k;i++){
		if(i<n)cin>>x,a.push({x,i});
		sum+=1LL*(i-a.top().S)*a.top().F;
		res[a.top().S]=i+1;
		a.pop();
	}
	cout<<sum<<endl;
	for(int i=0;i<n;i++)cout<<res[i]<<" ";
}
