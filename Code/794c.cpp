#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+7;
int n;
bool mode;
string s,t,ansl,ansr;

int32_t main(){
	cin>>s>>t;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	deque<char>a,b;
	for(int i=0;i<(s.size()+1)/2;i++)a.push_back(s[i]);
	for(int i=0;i<s.size()/2;i++)b.push_back(t[i]);
	for(int i=0;i<s.size();i++){
		if(i%2){
			if(!a.empty()&&a[0]>=b[0])mode=true;
			if(mode)ansr+=b.back(),b.pop_back();
			else ansl+=b[0],b.pop_front();
		}
		else{
			if(!b.empty()&&a[0]>=b[0])mode=true;
			if(mode)ansr+=a.back(),a.pop_back();
			else ansl+=a[0],a.pop_front();
		}
	}
	reverse(ansr.begin(),ansr.end());
	ansl+=ansr;
	cout<<ansl;
}
