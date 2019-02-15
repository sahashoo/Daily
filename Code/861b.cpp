///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;
pair<int,int>flt[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++)cin>>flt[i].F>>flt[i].S;
	set<int>ans;ans.clear();
	for(int i=1;i<=10000;i++){
		bool chk=true;
		for(int j=0;j<m;j++){
			if(flt[j].F/i+(flt[j].F%i?1:0)!=flt[j].S){
				chk=false;
				break;
			}
		}
		if(chk)ans.insert(n/i+(n%i?1:0));
	}
	if(ans.size()!=1)return cout<<-1,0;
	cout<<*ans.begin();
}
