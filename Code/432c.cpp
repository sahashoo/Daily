///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7;
int n,a[maxn];
bool mrk[maxn];
vector<int>prime;
vector<pair<int,int> >ans;

void gharbal(){
	for(int i=2;i<maxn;i++){
		if(mrk[i]==false){
			for(int j=i+i;j<maxn;j+=i)mrk[j]=true;
			prime.push_back(i);
		}
	}
}

void SWAP(int i,int j){
	while(i!=j){
		int k=upper_bound(prime.begin(),prime.end(),j-i+1)-prime.begin()-1;
		ans.push_back({i+1,i+prime[k]});
		swap(a[i],a[i+prime[k]-1]);
		i+=prime[k]-1;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	gharbal();
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],a[i]--;
	for(int i=0;i<n;i++){
		while(a[i]!=i)SWAP(i,a[i]);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)cout<<ans[i].F<<" "<<ans[i].S<<endl;
}
