#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int n,t,a,ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>a;
    double maxt=(double)a*n/180;
	double mina=maxn;
	for(int i=1; i<=n-2;i++){
        if(abs(i-maxt)<mina){
            mina=abs(i-maxt);
            ans=i;
        }
	}
	int x=(1-ans+n)%n;
	if(x==0)x=n;
	cout<<"1 2 "<<x;
}
