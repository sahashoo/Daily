#include<bits/stdc++.h>
using namespace std;
long long n,ts,tf,t,ans,MAXN=1e12+10;
int main(){
    cin>>ts>>tf>>t>>n;
	for(int i=0;i<n;i++){
        long long a;
		cin>>a;
        if(a<=tf-t){
            if(a&&ts-(a-1)<MAXN){MAXN=ts-a+1;ans=a-1;}
            ts=max(ts,a)+t;
        }
    }
    if(ts<=tf-t) ans=ts;
    cout<<ans<<endl;
}