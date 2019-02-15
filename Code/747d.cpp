///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=2e5+7,INF=1e18+7,mod=1e9+7;
int n,k,cnt,ans,t[maxn],a[maxn];
multiset<int>st;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<0)t[i]=1;
		cnt+=t[i];
	}
	if(cnt>k)return cout<<-1,0;
	if(t[0])ans++;
	int f=-1;
	for(int i=0;i<n;i++){
		if(t[i]&&f==-1)f=i;
		while(i<n-1&&t[i]==t[i+1])i++;
		if(i!=n-1)ans++;
	}
	if(f==-1)return cout<<0,0;
	int p=-1,c=1;
	for(int i=f;i<n;i++){
		int y=1;
		while(i+1<n&&t[i]==t[i+1])y++,i++;
		if(c==0&&i!=n-1)st.insert(y);
		if(c==0&&i==n-1)p=y;
		c=1-c;
	}
	while(st.size()&&cnt<k){
		int u=*st.begin();
		st.erase(st.begin());
		if(cnt+u<=k){
			cnt+=u;
			ans-=2;
		}
		else break;
	}
	if(p!=-1&&cnt+p<=k)ans--;
	cout<<ans;
}
