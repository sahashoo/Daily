///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
#define bug cout<<10<<endl;
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e6+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int day,a[maxn];
pair<int,int>b[maxn];
queue<int>frg;
// queue<pair<int,int> >buy;
deque<pair<int,int> >buy,mrkt;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int j=0;j<m;j++)cin>>b[j].F,b[j].S=j+1;
	sort(a,a+n);sort(b,b+m);
	for(int i=0;i<n;i++)frg.push(a[i]);
	for(int j=0;j<m;j++)mrkt.push_back(b[j]);
	while(frg.size()||mrkt.size()){
		int cnt=0;
		bool res=true;
		while(frg.size()&&frg.front()==day)frg.pop(),cnt++;
		while(mrkt.size()&&mrkt.front().F<day)mrkt.pop_front();
		while(cnt<k&&mrkt.size())
			buy.push_front(mrkt.front()),mrkt.pop_front(),cnt++;
		while(frg.size()&&cnt<k)frg.pop(),cnt++;
		if(cnt<k)res=false;
		if(cnt>k){
			if(buy.size()<cnt-k)return cout<<-1,0;
			while(cnt>k){
				if(buy.back().F>day)mrkt.push_front(buy.front());
				buy.pop_front();cnt--;
			}
		}
		if(res==false)
			if(frg.empty())break;
			else return cout<<-1,0;
		day++;
	}
	cout<<buy.size()<<endl;
	while(buy.size())cout<<buy.front().S<<" ",buy.pop_front();
}
