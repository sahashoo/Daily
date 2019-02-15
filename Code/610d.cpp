#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define all(a) a.begin(),a.end()
using namespace std;
const int MAXN=2e5+7;
int val[4*MAXN],rem[4*MAXN],ans,n,m;
pair<pair<int,int>,pair<int,int> >e[MAXN];
vector<int>vec;

void update(int x,int y,int v,int id=1,int l=0,int r=n) 
{	
	if(x>=r||l>=y)
		return;
	if(x<=l&&r<=y)
	{
		rem[id]+=v;
		return;
	}
	int mid=(l+r)/2,lc=id*2,rc=id*2+1;
	update(x,y,v,lc,l,mid);
	update(x,y,v,rc,mid,r);
	
	val[id] =( rem[lc]>0 ? vec[mid]-vec[l] : val[lc]);
	val[id]+=( rem[rc]>0 ? vec[r]-vec[mid] : val[rc]);
}

int32_t main() 
{
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(b>d)
		{
			swap(a,c);
			swap(b,d);
		}
		if(a>c)
		{
			swap(a,c);
			swap(b,d);
		}
		
		vec.push_back(b);
		vec.push_back(d+1);
		
		e[m]={{a,1},{b,d+1}};
		m+=1;
		e[m]={{c+1,-1},{b,d+1}};
		m+=1;
	}
	
	sort(all(vec));
	vec.erase(unique(all(vec)),vec.end());
	n=vec.size()-1;
	sort(e,e+m);
	
	int last=e[0].F.F,i=0;
	while(i<m) 
	{
		int now=e[i].F.F;
		ans+=( now-last ) * ( rem[1]>0 ? vec.back()-vec[0] : val[1] );
		
		while(i<m&&e[i].F.F==now) 
		{	
			int l=lower_bound( all(vec) , e[i].S.F )-vec.begin();
			int r=lower_bound( all(vec) , e[i].S.S )-vec.begin();
			update(l,r,e[i].F.S);
			i++;
		}
		last=now;
	}
	
	cout<<ans<<endl;
	
}