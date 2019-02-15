///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=7e4+100,INF=3e18+9237,mod=1e9+7;
map<string,int>mp;
string s[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++){
		for(int len=1;len<=9;len++){
			set<string>st;
			for(int l=0;l+len-1<9;l++){
				string t="";
				for(int j=l;j<l+len;j++)t=t+s[i][j];
				st.insert(t);
			}
			while(st.size())mp[*st.begin()]++,st.erase(*st.begin());
		}
	}
	// cout<<"***********************\n\n";
	for(int i=0;i<n;i++){
		bool chk=false;
		for(int len=1;len<=9;len++){
			for(int l=0;l+len-1<9;l++){
				string t="";
				for(int j=l;j<l+len;j++)t=t+s[i][j];
				if(mp[t]==1){
					cout<<t<<'\n';
					chk=true;
					break;
				}
			}
			if(chk)break;
		}
	}
	// cout<<"**********\n\n";
	// cout<<mp["000"];
}
