#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=5e5+7;
int n,ans,gh;
pair<int,int> arr[maxn];

int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i].w>>arr[i].q;
    sort(arr,arr+n);
    gh=arr[0].q;
    ans++;
    for(int i=0;i<n;i++){
        if(arr[i].w>gh){
            gh=arr[i].q;
            ans++;
        }
    }
    cout<<ans;
}
