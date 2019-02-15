//Maximum Continues SUM Subarray
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7;
int a[maxn],n;

int mcs(){
	int maxsum=-INF,cur = 0;
    for(int i=1;i<=n;i++){
		cur+=a[i];
		maxsum=max(maxsum,cur);
		cur=max((int)0,cur);
	}
	return maxsum;
}

int32_t main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<mcs();
}
