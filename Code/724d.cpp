#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7,INF=1e9+7;
string s,a;
int m;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>m>>s;
	for(char c='a';c<='z';c++){
		a.clear();
		bool check=true;
		int l=0,l2=0;
		for(auto x:s){
			l++;
			l2++;
			if(x<c)l=0,l2=0,a+=x;
			if(x==c)l2=0;
			if(l>=m){
				if(l2<m)l=l2,a+=c;
				else{check=false;break;}
			}
		}
		if(check){
			sort(a.begin(),a.end());
			cout<<a;return 0;
		}
	}

}
