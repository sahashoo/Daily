#include<bits/stdc++.h>
using namespace std;
const int nil=315,maxn=645;
int m,t,r,a[maxn],IS[maxn];
bool mrk[maxn];

bool Candle(int pos){
	while(pos>=0&&mrk[pos])pos--;
	if(pos<0)return false;
	mrk[pos]=true;
	for(int i=pos;i<pos+t&&i<maxn;i++)IS[i]++;
	return true;
}

int32_t main(){
	cin>>m>>t>>r;
	for(int i=0;i<m;i++)cin>>a[i];
	int res=0;
	for(int i=0;i<m;i++){
		while(IS[a[i]+nil]<r){
			if(Candle(a[i]+nil))res++;
			else return cout<<-1,0;
		}
	}
	cout<<res;
}