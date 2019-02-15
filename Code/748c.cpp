///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,cnt=0;
	string s;
	set<char>st;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='U'&&st.count('D'))st.clear(),cnt++;
		if(s[i]=='D'&&st.count('U'))st.clear(),cnt++;
		if(s[i]=='R'&&st.count('L'))st.clear(),cnt++;
		if(s[i]=='L'&&st.count('R'))st.clear(),cnt++;
		st.insert(s[i]);
	}
	cout<<cnt+1;
}
