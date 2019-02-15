#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e6+12;
int n,arr[maxn];

int32_t main(){
    cin>>n;
    arr[1]++;
    for(int i=1;i<maxn;i++){
        if(arr[i]==0){
            int j=2;
            while(j*i<maxn){
                arr[i*j]++;
                j++;
            }
        }
    }
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        int s=sqrt(a);
        if(s*s==a&&arr[s]==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
