#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int n,k,arr[maxn],t,f;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    k--;
    for(int i=0;i<n;i+=t){
        t=1;
        while(arr[i]==arr[i+t])t++;
        if(t*n>k){f=i;break;}
        k-=t*n;
    }
    cout<<arr[f]<<" "<<arr[k/t];
}
