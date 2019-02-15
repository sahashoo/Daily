///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,cnt,now=maxn,fas;
vector<int>pos[maxn];

void go(int x ,int p){
	int k=lower_bound(pos[x].begin(),pos[x].end(),p)-pos[x].begin();
	int z=(int)pos[x].size();z-=k;
	if(z==0)return;
	fas-=z;
	p=pos[x].back();
	while(z--)pos[x].pop_back();
	if(!fas)return;
	if(pos[x].empty()){
		while(pos[x].empty())x++;
		now=x;
		go(x,p);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		pos[a].push_back(i);
		now=min(now,a);
	}
	fas=n;
	while(fas){
		cnt+=fas;
		while(pos[now].empty())now++;
		go(now,pos[now][0]);
	}
	cout<<cnt;
}

/*int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].F;
		a[i].S=i;
	}
	//for(int )
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		
		if(a[i].S>a[i-1].S)cnt+=a[i].S-a[i-1].S;
		else cnt+=n-a[i-1].S+a[i].S;
		cnt-=b[a[i].F];
	}
	//cout<<endl;
	cout<<cnt;
}*/
