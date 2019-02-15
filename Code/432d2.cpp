#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
int f[MAXN],cnt[MAXN],ans;
bool mrk[MAXN];

int32_t main(){
	string s;cin>>s;
	int k=0,n=s.size();
	for(int i=1;i<n;i++){
		while(k&&s[i]!=s[k])
			k=f[k];
		k+=(s[i]==s[k]);
		f[i+1]=k;
    }
	mrk[n]=true;
	for(int i=n;i>0;i--){
		mrk[f[i]]|=mrk[i];
		cnt[i]++;
		cnt[f[i]]+=cnt[i];
		ans+=(mrk[i]==1);
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)
		if(mrk[i]==true)
			cout<<i<<' '<<cnt[i]<<'\n';
}