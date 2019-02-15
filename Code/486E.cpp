#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
int a[MAXN],lst[MAXN],n,dp_lis[MAXN],dp_lds[MAXN],len_lis,cnt[MAXN],ans[MAXN];

int LIS(){
    memset(lst,63,sizeof lst );
    int res=0;
    for(int i=1;i<=n;i++){
        int j=lower_bound(lst+1,lst+n+1,a[i])-lst;
        dp_lis[i]=j;
        lst[j]=a[i];
        res=max(res,dp_lis[i]);
    }
    return res;
}

void LDS(){
    // memset(lst,-63,sizeof lst );
	int res=0;
    for(int i=n;i>=1;i--){
		int j=lower_bound(lst+1,lst+n+1,-a[i])-lst;
		dp_lds[i]=j;
        lst[j]=-a[i];
	}
}

bool flg[MAXN];
void check(){
    for(int i=1;i<=n;i++)
        if(dp_lis[i]+dp_lds[i]!=len_lis+1)flg[i]=true;
        else flg[i]=false,cnt[dp_lis[i]]++;
    for(int i=1;i<=n;i++)
        if(flg[i]==false){
            if(cnt[dp_lis[i]]>1)ans[i]=2;
            else ans[i]=3;
        }
        else ans[i]=1;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	len_lis=LIS();LDS();
	check();
    for(int i=1;i<=n;i++)cout<<ans[i];
    cout<<endl;
}
