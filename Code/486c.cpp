///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int n,pos,lst=-INF,fst=INF,res;
string s;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>pos>>s;
	pos--;
	for(int i=0;i<n;i++){
		if(s[i]!=s[n-i-1]){
			if((pos<n/2&&i<n/2)||(pos>=n/2&&i>=n/2)){
				lst=max(lst,i),fst=min(fst,i);
				int x=abs(s[i]-s[n-i-1]);
				res+=min(x,26-x);
			}
		}
	}
	if(fst==INF)return cout<<0,0;
	if(pos<=fst)res+=lst-pos;
	else if(pos>=lst)res+=pos-fst;
	else res+=lst-fst+min(pos-fst,lst-pos);
	cout<<res;
}
