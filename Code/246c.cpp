#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=55;
int n,k,l,arr[maxn],p;
vector<int> res[1500];

void act(int len){
    //cout<<len<<"**"<<endl<<endl;
    for(int i=n-len+1;i>0;i--){
        if(k<=0)return ;
        p++;
        k--;
      //  cout<<p<<" ";
        for(int j=n;j>n-len+1;j--)res[p].push_back(arr[j]);
        res[p].push_back(arr[i]);
        //cout<<arr[i]<<"*";
        //cout<<endl<<endl;
    }
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    //for(int i=0;i<=n;i++)cout<<arr[i]<<" ";
    //cout<<endl<<endl;
    while(k>0)l++,act(l);
    for(int i=1;i<=p;i++){
        cout<<res[i].size()<<" ";
        for(int j=0;j<res[i].size();j++)cout<<res[i][j]<<" ";
        cout<<endl;
    }
}
