///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N=510;
int n,m;
vector<int>g[N];
bool mrk[N][N][3];
pair<pair<int,int>,bool>how[N][N][3],nil;

inline void BFS(){
	queue<pair<pair<int,int>,bool> >Q;Q.push({{1,n},0});
	while(Q.size()){
		pair<pair<int,int>,bool>v=Q.front();Q.pop();
		if(v.S==false){
			for(auto u:g[v.F.F])
				if(mrk[u][v.F.S][1]==false)
					Q.push({{u,v.F.S},1}),
					how[u][v.F.S][1]=v,
					mrk[u][v.F.S][1]=true;
		}
		else{
			for(auto u:g[v.F.S])
				if(mrk[v.F.F][u][0]==false&&v.F.F!=u)
					Q.push({{v.F.F,u},0}),
					how[v.F.F][u][0]=v,
					mrk[v.F.F][u][0]=true;
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0,u,v;i<m;i++)
		cin>>u>>v,g[v].push_back(u),g[u].push_back(v);
	BFS();
	if(mrk[n][1][0]==false)return cout<<-1,0;
	vector<int>mmd,mjd;
	pair<pair<int,int>,bool>v={{n,1},0};	
	while(v.F.F!=1||v.F.S!=n||v.S!=0){
		mmd.push_back(v.F.F);
		mjd.push_back(v.F.S);
		v=how[v.F.F][v.F.S][v.S];
	}
	mmd.push_back(1);
	mjd.push_back(n);
	reverse(mmd.begin(),mmd.end());
	reverse(mjd.begin(),mjd.end());
	cout<<mmd.size()/2<<endl;
	for(int i=0;i<mmd.size();i+=2)cout<<mmd[i]<<" ";
	cout<<endl;
	for(int i=0;i<mmd.size();i+=2)cout<<mjd[i]<<" ";
}	