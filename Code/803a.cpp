#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=107;
int a[maxn][maxn],k,n;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(k<=0)break;
			if(i==j)a[i][j]=1,k--;
			else if(k>1)a[i][j]=1,a[j][i]=1,k-=2;
		}
	}
	if(k)return cout<<-1,0;
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){cout<<a[i][j]<<" ";}cout<<endl;}
}
