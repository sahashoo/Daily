#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int n,arr[maxn],dp[maxn],par[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		dp[i]=maxn;
		par[i]=i;
	}
	dp[1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(arr[j]+j>=i){
				if(dp[i]>dp[j]+1){
					dp[i]=dp[j]+1;
					par[i]=j;
				}
			}
		}
		//cout<<dp[i]<<" ";
	}
	cout<<dp[n]<<endl;
	while(par[n]!=n){cout<<par[n]<<" ";n=par[n];}
}