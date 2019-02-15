///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
int dist[307][307],n,k;
vector<int>ans;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>dist[i][j];
		}
	}
	cin>>k;
	while(k--){
		int u,v,w,sum=0;cin>>u>>v>>w;
		if(w<dist[u][v]){
			dist[u][v]=dist[v][u]=w;
			for(int l=1;l<=n;l++){
				for(int i=1;i<=n;i++){
					dist[i][u]=dist[u][i]=min(dist[u][i],dist[v][i]+dist[u][v]);
				}
			}
			for(int l=1;l<=n;l++){
				for(int i=1;i<=n;i++){
					dist[i][v]=dist[v][i]=min(dist[v][i],dist[u][i]+dist[v][u]);
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][u]+dist[u][j]);
					dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][v]+dist[v][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i>j)sum+=dist[i][j];
			}
		}
//		cout<<sum<<endl;
		ans.push_back(sum);
    }
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}