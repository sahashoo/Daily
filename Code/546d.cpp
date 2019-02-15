#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+100;
int cnt[N],sum[N];
bool mrk[N];

int decompos(int k,int p){
	int res=0;
	while(k%p==0)k/=p,res++;
	return res;
}

void gharbal(){
	mrk[1]=true;
	for(int i=2;i<N;i++){
		if(mrk[i]==false){
			int j=1;
			while(j*i<N){
				mrk[j*i]=true;
				cnt[j*i]+=decompos(j,i)+1;
				j++;
			}
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	gharbal();
	for(int i=1;i<N;i++)sum[i]=sum[i-1]+cnt[i];
	int t;cin>>t;
	for(int i=0,l=0,r=0;i<t;i++)cin>>r>>l,cout<<sum[r]-sum[l]<<'\n';
}