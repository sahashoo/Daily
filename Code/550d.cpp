///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int k;
vector<pair<int,int> >E;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>k;
	if(k%2==0)return cout<<"NO",0;
	if(k==1)return cout<<"YES \n 2 1 \n 1 2 \n",0;
	int n=k*2+4;
	E.push_back({1,2});
	for(int i=1;i<k;i++){
		E.push_back({1,i+2});
		E.push_back({2,k+i+3});
	}
	for(int i=1;i<=k+1;i++){
		if(i!=k){
			E.push_back({k+2,i+2});
			E.push_back({k+k+3,k+i+3});
		}
		if(i!=k&&i!=k+1){
			E.push_back({k+3,i+2});
			E.push_back({k+k+4,k+i+3});
		}
	}
	for(int i=1;i<k;i++){
		for(int j=i+1;j<k;j++){
			if(i+j!=k){
				E.push_back({i+2,j+2});
				E.push_back({k+i+3,k+j+3});
			}
		}
	}
	cout<<"YES"<<endl<<n<<" "<<E.size()<<endl;
	for(auto e:E)cout<<e.F<<" "<<e.S<<endl;
}
