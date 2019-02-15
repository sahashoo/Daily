#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=3e5+1;
const int INF=1e9+7;
int n,lt,lw,ans=1;
priority_queue<pair<int,int> >sml;
priority_queue<int,vector<int>,greater<int> >big;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>lt>>lw;
	n-=1;
	for(int i=0;i<n;i++){
		int t,w;cin>>t>>w;
		if(t<=lt)sml.push({t,w});
		else big.push(w-t+1),ans++;
	}
	while(big.size()&&big.top()<=lt){
		lt-=big.top();
		big.pop();
		while(sml.size()&&lt<sml.top().q){
			big.push((sml.top().w)-(sml.top().q)+1);
			sml.pop();
		}
		ans=min(ans,(int)big.size()+1);
	}
	cout<<ans<<endl;
}
