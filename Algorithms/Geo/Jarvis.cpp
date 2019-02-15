#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;

struct point{int x,y;}a[MAXN];

// class convex_hull{
	inline int cross(point p,point q,point r){
		return ((q.y-p.y) * (r.x-q.x) - (q.x-p.x) * (r.y-q.y)<0) ;
	}
	vector<point> ConvexHull(point a[],int n){
		vector<point>hull;
		if(n<3)return hull;
		int l=0;//left most point
		for(int i=1;i<n;i++)
			if(a[i].x<a[l].x)l=i;
		int p=l,q;
		do{
			hull.push_back(a[p]);
			q=(p+1)%n;
			for(int i=0;i<n;i++)
			   if(cross(a[p],a[i],a[q]))q=i;
			p = q;
		}while(p!=l);
		return hull;
	}
// };

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y;
	vector<point>hull=ConvexHull(a,n);
	cout<<hull.size()<<endl;
	for(auto p:hull)cout<<p.x<<" "<<p.y<<endl;
	
}
