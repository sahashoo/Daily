/// read! read! read! read! read! read!
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e4+7;
vector<int>g[207],res[207],vec,vc[MAXN];
set<int>st[MAXN];

bool all(int a,int b){
	for(int x:g[a])
		if(st[x].find(b)==st[x].end())return false;
	return true;
}

bool mrk[207],flg[207][207];
void set_find(int a){
	mrk[a]=true;
	vec.push_back(a);
	for(int x:res[a])
		if(mrk[x]==false)set_find(x);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n;m=n*(n-1)/2;
	for(int i=0;i<m;i++){
		int x,a;cin>>x;
		while(x--){
			cin>>a;
			g[a].push_back(i);
			st[i].insert(a);
			vc[i].push_back(a);
			flg[a][a]=true;
			// if(a==7)cout<<"HERE "<<i<<endl;
		}
	}
	if(m==1){
		cout<<"1 "<<vc[0][0]<<"\n"<<vc[0].size()-1<<' ';
		for(int i=1;i<vc[0].size();i++)cout<<vc[0][i]<<" ";
		return 0;
	}
	for(int ind=0;ind<m;ind++){
		for(int x=0;x<vc[ind].size();x++)
		for(int y=x+1;y<vc[ind].size();y++){
			int i=vc[ind][x],j=vc[ind][y];
			if(flg[i][j]==false){
				flg[i][j]=flg[j][i]=true;
				if(all(i,j)==true)
					res[i].push_back(j),
					res[j].push_back(i);
			}
		}
	}
	// cout<<endl;
	for(int i=1;i<201;i++){
		if(flg[i][i]&&mrk[i]==false){
			vec.clear();
			set_find(i);
			cout<<vec.size()<<" ";
			for(auto x:vec)cout<<x<<" ";
			cout<<"\n";
		}
	}
	// vec.clear();
	// set_find(7);
	// cout<<vec.size()<<" ";
	// for(auto x:vec)cout<<x<<" ";
	// cout<<"\n";
	// cout<<mrk[7]<<endl;
	// cout<<flg[7][7]<<endl;
}