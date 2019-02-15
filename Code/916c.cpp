/// read! read! read! read! read! read!
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
const int INF=1e9;
int m,n;
vector<int>primes;

bool flg[MAXN];
void find_prime_num(){
	for(int i=2;i<MAXN;i++){
		if(flg[i]==false){
			primes.push_back(i);
			for(int j=i+i;j<MAXN;j+=i){
				flg[j]=true;
			}
		}
	}
}

void make_mst(){
	int mn=INF;
	for(int x:primes)
		if(x>=n-1)mn=min(mn,x);
	cout<<mn<<" "<<mn<<'\n';
	mn-=n-2;
	for(int i=1;i<n;i++){
		cout<<i<<" "<<i+1<<" "<<(i==n-1?mn:1)<<'\n';
		m--;
	}
}

void make_waste_edege(){
	int v=1;
	while(m>0){
		for(int u=v+2;u<=n&&m;u++){
			cout<<v<<" "<<u<<" "<<INF<<'\n';
			m--;
		}
		v++;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	find_prime_num();
	make_mst();
	make_waste_edege();
	
}