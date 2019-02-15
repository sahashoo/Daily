///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1507;
int n,dp[150][maxn],q;
string s;
vector<int>ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>s;
	for(char c='a';c<='z';c++){
		for(int i=0;i<n;i++){
			int cnt=0;
			for(int j=i;j<n;j++){
				if(s[j]!=c)cnt++;
				dp[c][cnt]=max(dp[c][cnt],j-i+1);
			}
        }
		for(int i=1;i<maxn;i++)dp[c][i]=max(dp[c][i],dp[c][i-1]);
    }
	cin>>q;
	while(q--){
		int m;char c;cin>>m>>c;
		ans.push_back(dp[c][m]);
	}
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
}
