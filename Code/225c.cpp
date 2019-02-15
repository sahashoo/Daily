#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7,INF=1e9+1000;
int B[N],W[N],bstB[N],bstW[N],n,m,x,y;

int32_t main(){
	cin>>n>>m>>x>>y;
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			char c;cin>>c;
			B[j]+=(c=='#');
			W[j]+=(c=='.');
		}
	}
	for(int i=1;i<=m;i++)B[i]+=B[i-1],W[i]+=W[i-1];
	fill(bstB,bstB+N,INF);bstB[0]=0;
	fill(bstW,bstW+N,INF);bstW[0]=0;
	for(int i=1;i<=m;i++){
		for(int j=max(0,i-y);j<=i-x;j++){
			bstB[i]=min(bstB[i],bstW[j]+B[i]-B[j]);
			bstW[i]=min(bstW[i],bstB[j]+W[i]-W[j]);
		}
	}
	cout<<min(bstB[m],bstW[m]);
}