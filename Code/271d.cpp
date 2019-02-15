///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Hash=31;
const int mod=1e17+7;
unordered_set<int>st;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int k;string s,bad;
	cin>>s>>bad>>k;
	for(int l=0;l<s.size();l++){
		int tmp=0,cnt=0;
		for(int r=l;r<s.size();r++){
			if(bad[s[r]-'a']=='0')cnt++;
			if(cnt>k)break;
			tmp=(tmp*Hash+s[r]-'a'+1)%mod;
			st.insert(tmp);
		}
	}
	cout<<st.size();
}
