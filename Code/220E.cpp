#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int a[MAXN],dpl[MAXN],dpr[MAXN],t[MAXN];
vector<int>vec;

void add(int pos,int val,int* tree){
	for(int p=pos+1;p<MAXN;p+=(p&(-p)))
		tree[p]+=val;
	return ;
}

int get(int pos,int* tree){
	int ret=0;
	for(int p=pos;p>0;p-=(p&(-p)))
		ret+=tree[p];//+=val;
	return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i],vec.push_back(a[i]);
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	for(int i=0;i<n;i++)
		t[i]=lb(all(vec),a[i])-vec.begin()+1;
	int inv=0;
	for(int i=n-1;i>=0;i--)
		inv+=get(t[i],dpr),add(t[i],1,dpr);
	
	// cout<<"MAMA"<<endl;
	int ans=0,pos=0;
	for(int i=0;i<n;i++){
		inv+=get(t[i],dpr)+i-get(t[i]+1,dpl);
		add(t[i],1,dpl);
		while(pos<n&&(inv>k||pos<=i))
			inv-=get(t[pos],dpr)+i+1-get(t[pos]+1,dpl),
			add(t[pos],-1,dpr),pos++;
		ans+=n-pos;
	}
	cout<<ans;
}
