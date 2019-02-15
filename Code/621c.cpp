#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e9+100;
int n,p,l[maxn],r[maxn];

int32_t main(){
	cin>>n>>p;
	for(int i=0;i<n;i++)cin>>l[i]>>r[i];
	double res=0.0;
	for(int i=0;i<n;i++){
		int nxt=(i+1)%n;
		int cnt=(r[i]/p-(l[i]-1)/p)*(r[nxt]-l[nxt]+1)+
                (r[nxt]/p-(l[nxt]-1)/p)*(r[i]-l[i]+1)-
                (r[i]/p-(l[i]-1)/p)*(r[nxt]/p-(l[nxt]-1)/p);
        int tot=(r[i]-l[i]+1)*(r[nxt]-l[nxt]+1);
        res+=(double)cnt/tot;
    }
	cout<<fixed<<setprecision(12)<<(double)res*2000;
    cout<<endl;
}

/*
int32_t main(){
	cin>>n>>p;
	for(int i=0;i<n;i++)cin>>l[i]>>r[i];
	double res=0.0;
	for(int i=0;i<n;i++){
		int nxt=(i+1)%n;
		int cnt=(((r[i]-l[i]+1)/p)*(r[nxt]-l[nxt]+1))+
				(((r[nxt]-l[nxt]+1)/p)*(r[i]-l[i]+1))-
				(((r[i]-l[i]+1)/p)*(r[nxt]-l[nxt]+1)/p);
		int tot=((r[i]-l[i]+1)*(r[nxt]-l[nxt]+1));
		res+=(double)cnt/tot;
	}
//	long double ans=(long double)res*2000;
	cout<<fixed<<setprecision(12)<<(double)res*2000;
}*/
/*
3 3
3 3
2 4
1 1
*/