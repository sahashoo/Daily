///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1000000000000;
int A,B,n,l,t,m,r;

bool check(int len){
	int sum=A+(B*(l-1));
	int mx=A+(B*(len-1));
	if(mx<=t&&mx+sum<=2*m*t/(len-l+1))return true;
	else return false;
}

int BS(int L,int R){
	if(L>R)return r;
	int mid=L+R>>1;
	if(check(mid)){
		r=mid;
		return BS(mid+1,R);
	}
	else return BS(L,mid-1);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>A>>B>>n;
	while(n--){
		cin>>l>>t>>m;
		r=l-1;
		BS(l,INF);
		if(r>=l)cout<<r<<'\n';
		else cout<<-1<<'\n';
	}
}
