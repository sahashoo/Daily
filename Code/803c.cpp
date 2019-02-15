#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int d,n,k;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if(k>1000000||k*(k+1)/2>n)return cout<<-1,0;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            if(n/i>=k*(k+1)/2)d=max(d,i);
            if(i>=k*(k+1)/2)d=max(d,n/i);
        }
    }
    for(int i=1;i<k;i++)cout<<d*i<<" ";
    cout<<n-d*k*(k-1)/2<<endl;
}
