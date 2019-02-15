///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,cnt,dp[maxn][255];
string s;
set<char>st;

bool check(int mid){
	for(int i=mid-1;i<n;i++){
		int t=0;
		for(int j='A';j<='z';j++){
			if(i-mid>=0&&dp[i][j]-dp[i-mid][j]>0)t++;
			else if(i-mid==-1&&dp[i][j]>0)t++;
		}
		if(t==cnt)return true;
	}
	return false;
}

int BS(int l,int r){
	if(r-l<=1)return r;
	int mid=l+r>>1;
	bool mrk=false;
	if(check(mid))return BS(l,mid);
	else return BS(mid,r);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>s;
	for(int i=0;i<n;i++){
		st.insert(s[i]);
		dp[i][s[i]]=1;
		if(i!=0){
			for(int j='A';j<='z';j++){
				dp[i][j]+=dp[i-1][j];
			}
		}
	}
	cnt=st.size();
	cout<<BS(0,n);
}
