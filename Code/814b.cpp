#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e3+7;
int n,a[maxn],b[maxn],ch,c[5],p[maxn],mis[maxn];
int32_t main(){
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];mis[a[i]]++;}
    for(int i=1;i<=n;i++){
        cin>>b[i];
        mis[b[i]]++;
        if(b[i]!=a[i]){ch++;c[ch]=i;}
        else p[i]=a[i];
    }
    if(ch==2){
		if(mis[a[c[1]]]<mis[b[c[1]]])p[c[1]]=a[c[1]];
		else p[c[1]]=b[c[1]];
		if(mis[a[c[2]]]<=mis[b[c[2]]])p[c[2]]=a[c[2]];
		else p[c[2]]=b[c[2]];
    }
    if(ch==1){
        for(int i=1;i<=n;i++)if(mis[i]==0)p[c[1]]=i;
    }
    for(int i=1;i<=n;i++)cout<<p[i]<<" ";
}