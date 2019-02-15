#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=3e18+9237;
const int maxn=1e5+7;
int a[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int out=3;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==out)return cout<<"NO",0;
		int x;
		if(a[i]==1&&out==2)x=3;
		else if(a[i]==1&&out==3)x=2;
		else if(a[i]==2&&out==3)x=1;
		else if(a[i]==2&&out==1)x=3;
		else if(a[i]==3&&out==2)x=1;
		else if(a[i]==3&&out==1)x=2;
		out=x;
	}
	cout<<"YES";
}
