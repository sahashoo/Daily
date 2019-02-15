///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+7;
int n,t,p[maxn],qq[maxn],copyp[maxn],len;
bool q[maxn];
int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;for(int i=0;i<n;i++)cin>>p[i];
	cin>>t;for(int i=0;i<t;i++)cin>>qq[i],q[qq[i]-1]=true;
	for(int i=n-1;i>=0;i--){
		if(q[i]||len==0||p[i]!=copyp[len-1]){
			copyp[len++]=p[i];
			p[i]=-p[i];
		}
		else len--;
	}
	if(len==0){cout<<"YES\n";for(int i=0;i<n;i++)cout<<p[i]<<" ";}
	else cout<<"NO";

}
