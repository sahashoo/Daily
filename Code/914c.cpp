/// read! read! read! read! read! read!
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e3+7;
const int mod=1e9+7;
int ans,sln,dist[MAXN],C[MAXN][MAXN],cnt;
vector<int>nxt;

int add(int a,int b){
	a+=b;
	a-=mod*(a>=mod);
	a+=mod*(a<0);
	return a;
}

void precompute(){
	C[0][0]=1;
	for(int i=1;i<MAXN;i++){
		C[i][i]=C[i][0]=1;
		for(int j=1;j<i;j++)
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	}
	dist[1]=0;
	for(int i=2;i<MAXN;i++){
		dist[i]=dist[__builtin_popcount(i)]+1;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;cin>>s;
	int k;cin>>k;
	if(k==0)return cout<<1,0;
	precompute();
	sln=s.size();
	for(int i=1;i<=sln;i++){
		if(dist[i]+1==k){
			ans=add(ans,C[sln][i]);
			int cur=0;
			for(int j=0;j<sln;j++){
				if(s[j]=='0'&&cur<i)
					ans=add(ans,-C[sln-j-1][i-cur-1]);
				cur+=(s[j]=='1');
			}
		}
	}
	if(k==1)ans=add(ans,-1);//*(k==1);
	cout<<ans;
	// cout<<endl<<C[5][3];
}