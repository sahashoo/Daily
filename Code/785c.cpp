#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=2e9;
int n,m;

void bs(){
    n-=m;
    int l=0,r=maxn;
    while(l<r){
        int mid=(l+r)/2;
        int val=mid*(mid+1)/2;
        if(val>=n)r=mid;
        else l=mid+1;
    }
    cout<<l+m<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(n<=m+1)cout<<n<<endl;
    else bs();
}
