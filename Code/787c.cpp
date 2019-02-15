///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=7000+7,INF=3e18+9237,mod=1e9+7;
int w[N][2],l[N][2],p1[N],p2[N],n,k1,k2;
bool mrk[N][2];

void game(int ind,int player){
    mrk[ind][player]=true;
    if(player==0){
        for(int i=0;i<k2;i++){
            int ch=(ind-p2[i]+n)%n;
            if(ch==0)continue;
            if(mrk[ch][!player])continue;

            if(w[ind][player]&& ++l[ch][!player]==k2)game(ch,!player);
            
			else if(!w[ind][player])w[ch][!player]=true,game(ch,!player);
        }
    }
	else{
        for(int i=0;i<k1;i++){
            int ch=(ind-p1[i]+n)%n;
            if(ch==0)continue;
            if(mrk[ch][!player])continue;
			
            if(w[ind][player]&& ++l[ch][!player]==k1)game(ch,!player);
			
            else if(!w[ind][player])w[ch][!player]=true,game(ch,!player);
        }
    }
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k1;
	for(int i=0;i<k1;i++)cin>>p1[i];
    cin>>k2;
	for(int i=0;i<k2;i++)cin>>p2[i];
	game(0,1);
	game(0,0);
	for(int i=1;i<n;i++){
		if(mrk[i][0]==false)cout<<"Loop ";
		else{
			if(w[i][0])cout<<"Win ";
			else cout<<"Lose ";
		}
	}
	cout<<endl;
	for(int i=1;i<n;i++){
		if(mrk[i][1]==false)cout<<"Loop ";
		else{
			if(w[i][1])cout<<"Win ";
			else cout<<"Lose ";
		}
    }
}