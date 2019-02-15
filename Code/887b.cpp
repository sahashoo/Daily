///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int a[5][7],n,mrk[5];

bool check(int num){
	if(num==0)return true;
	bool ret=false;
	for(int i=0;i<n;i++)
		for(int j=0;j<6;j++)
			if(a[i][j]==num%10&&mrk[i]==false){
				mrk[i]=true;
				ret|=check(num/10);
				mrk[i]=false;
			}
	return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0,x;j<6;j++)
			cin>>a[i][j];
	for(int i=1;i<=1000;i++)
		if(check(i)==false)return cout<<i-1,0;
	cout<<999;
}
