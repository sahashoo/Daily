/// read! read! read! read! read! read!
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7;
int seg[4*MAXN],n;

int gcd(int a,int b){return(b?gcd(b,a%b):a);}

void update(int x,int val,int v=1,int l=0,int r=n){
	if(r<=x||l>x)return ;
	if(r-l<=1){
		seg[v]=val;
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	update(x,val,lc,l,mid);
	update(x,val,rc,mid,r);
	seg[v]=gcd(seg[lc],seg[rc]);
}

int query(int x,int y,int val,int k,int v=1,int l=0,int r=n){
	// cout<<"MAMA "<<v<<endl;
	if(l>=y||r<=x||k>=2)return k;
	if(x<=l&&y>=r){
        if(seg[v]%val==0)return k;
        else if(k>=1)return 2;
        while(r-l>1){
			int mid=(l+r)/2,lc=v*2,rc=v*2+1;;
            if(seg[lc]%val==0){
                l=mid;
				v=rc;
            }
            else if(seg[rc]%val==0){
                r=mid;
                v=lc;
            }
            else return 2;
        }
        return 1;
    }
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;;
	return query(x,y,val,k,lc,l,mid)+query(x,y,val,0,rc,mid,r);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0,a;i<n;i++)
		cin>>a,update(i,a);
	int q;cin>>q;
	while(q--){
		int t,x,l,r,val;cin>>t;
		if(t==1){
			cin>>l>>r>>val;
			int tmp=query(l-1,r,val,0);
			// cout<<"--**-- "<<val<<" "<<tmp<<" : ";
			if(tmp<2)cout<<"YES\n";
			else cout<<"NO\n";
		}
		else{
			cin>>x>>val;
			update(x-1,val);
		}
	}
}
