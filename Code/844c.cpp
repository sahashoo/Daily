#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;

vector<vector<int> >res;
pair<int,int>b[maxn];
int n;
bool mrk[maxn];

void input(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>b[i].F,b[i].S=i;
	sort(b,b+n);
}

void act(){
	vector<int>tmp;
	for(int i=0;i<n;i++){
		if(mrk[i]==false){
			int v=i;
			res.push_back(tmp);
			while(mrk[v]==false){
				mrk[v]=true;
				res.back().push_back(v);
				v=b[v].S;
			}
		}
	}
}

void output(){
	cout<<res.size()<<endl;
	for(auto vec:res){
		cout<<vec.size()<<" ";
		for(auto u:vec)cout<<u+1<<" ";
		cout<<endl;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	input();
	act();
	output();
}