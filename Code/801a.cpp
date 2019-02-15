///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int cnt;
bool mrk[1000];
int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size()-1;i++)if(s[i]=='V'&&s[i+1]=='K'&&mrk[i]==false&&mrk[i+1]==false)cnt++,mrk[i]=true,mrk[i+1]=true;
	for(int i=0;i<s.size()-1;i++)if(((s[i]=='K'&&s[i+1]=='K')||(s[i]=='V'&&s[i+1]=='V'))&&mrk[i]==false&&mrk[i+1]==false){cnt++;break;}
	cout<<cnt;
}
