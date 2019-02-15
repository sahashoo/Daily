#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int b[maxn],n,maxb,k;
pair<int,int>a[maxn];
set<int> ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].q;
        a[i].w=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(b[i]>b[maxb])maxb=i;
    }
    sort(a+1,a+n+1);
    ans.insert(a[n].w);
    if(maxb!=a[n-1].w)ans.insert(maxb);
    int i=n-1;
    for(i=n-1;i>1;i-=2){
        if(b[a[i].w]>=b[a[i-1].w])ans.insert(a[i].w);
        else ans.insert(a[i-1].w);
    }
    if(i==1&&ans.size()<(n/2)+1)ans.insert(a[i].w);
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<" ";
}
