#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18+7;
int n,m;

int BS(int l,int r){
	if(r-l<=1)return r;
	int mid=l+r>>1;
	int a=mid/2,b=mid/3,c=mid/6;
	a=a-c,b=b-c;
	if(n-a+m-b<=c&&n-a<=c&&m-b<=c)return BS(l,mid);
	else return BS(mid,r);
}

int32_t main(){
	cin>>n>>m;
	cout<<BS(0,INF);
}