///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int cnt[107];
bool mrk[107][255];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	char c;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>c;
			if(mrk[j][c]==false)
				cnt[j]++,mrk[j][c]=true;
		}
	int res=cnt[0];
	for(int j=1;j<m;j++)
		res=((res*cnt[j])%mod);//)%mod;
	cout<<res;
}