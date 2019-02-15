///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1007;
//struct PRSN{int t,s,f,cnt;}a[maxn];
int n,t[maxn],s[maxn],f[maxn],cnt[maxn];

int grt(int t1,int s1,int f1,int t2,int s2,int f2){
	if(s1<f1!=s2<f2){
		if(s1>f1)swap(t1,t2),swap(s1,s2),swap(f1,f2);
		int x=s2+t2+s1-t1;
		return s1*2<=x&&x<=f1*2&&f2*2<=x&&x<=s2*2;
	}
	if(s1>f1)s1=-s1,f1=-f1,s2=-s2,f2=-f2;
	return t1-s1==t2-s2&&min(f1,f2)>=max(s1,s2);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>t[i]>>s[i]>>f[i];
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(grt(t[i],s[i],f[i],t[j],s[j],f[j]))cnt[i]++,cnt[j]++;
	for(int i=0;i<n;i++)cout<<cnt[i]<<" ";
}
