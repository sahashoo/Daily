///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e7+7;
bool mrk[maxn];
int res[maxn],cnt[maxn];

void precompute(){
	mrk[1]=true;
	for(int i=2;i<maxn;i++){
		if(mrk[i]==false)
			for(int d=i;d<maxn;d+=i)
				res[i]+=cnt[d],mrk[d]=true,d+=i;
	}
	for(int i=1;i<maxn;i++)res[i]+=res[i-1];
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,l,r;cin>>n;
	for(int i=0,x;i<n;i++)cin>>x,cnt[x]++;
	precompute();
	cin>>m;
	while(m--){
		cin>>l>>r;
		if(l>maxn&&r>maxn){
			cout<<"0\n";
			continue;
		}
		if(l>maxn)l=maxn-1;
		if(r>maxn)r=maxn-1;
		cout<<res[r]-res[l-1]<<'\n';
	}
}
