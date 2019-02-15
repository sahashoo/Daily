///Age Yekam Bekshi Beham is NO Problem .-.
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,c,a[200][200][20];//,p[101][101];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q>>c;
	for(int i=0;i<n;i++){
		int x,y,s;cin>>x>>y>>s;
		a[x][y][s]++;
	}
	for(int i=0;i<=c;i++){
		for(int x=1;x<=101;x++){
			for(int y=1;y<=101;y++){
				a[x][y][i]+=a[x-1][y][i]+a[x][y-1][i]-a[x-1][y-1][i];
			}
		}
	}
	//cout<<"HERE"<<endl;
	while(q--){
		int sum=0,x1,x2,y1,y2,t;cin>>t>>x1>>y1>>x2>>y2;
		for(int i=0;i<=c;i++){
			sum+=((i+t)%(c+1))*(a[x2][y2][i]-a[x1-1][y2][i]-a[x2][y1-1][i]+a[x1-1][y1-1][i]);
		}
		cout<<sum<<'\n';
	}
}