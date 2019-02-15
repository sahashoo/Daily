#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=2e5+7;
int n,arr[maxn],last0,first0=maxn,ans[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ans[i]=maxn+10;
        if(arr[i]==0){
            first0=min(first0,i);
            last0=max(last0,i);
        }
    }
    int c=0;
    for(int i=first0;i<=n;i++){
        if(arr[i]==0)c=0;
        ans[i]=c;
        c++;
    }
    for(int i=last0;i>0;i--){
        if(arr[i]==0)c=0;
        ans[i]=min(c,ans[i]);
        c++;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
