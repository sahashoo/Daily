#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int a,b,fact[20];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0]=1;
    for(int i=1;i<=20;i++)fact[i]=fact[i-1]*i;
    cin>>a>>b;
    cout<<fact[min(a,b)];
}
