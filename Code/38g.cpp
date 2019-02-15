// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// const int N=1e5+7;
// const int SQ=317;
// multiset<int>st[SQ*2];
// deque<int>Q[SQ*2],ind[SQ*2];
// int n,cnt_blk=1;

// void add(int a,int c,int id,int i)
// {
	// while(c>SQ&&i>0)
	// {
		// int mx=-1*(*st[i-1].begin());
		// if(mx>a)
			// break;
		// else 
			// i--,c-=SQ;
	// }
	// vector<int>temp,tmp;
	
	// while(c&&Q[i].size()&&Q[i].back()<a)
	// {
		// temp.push_back(Q[i].back());
		// tmp.push_back(ind[i].back());
		// Q[i].pop_back();
		// ind[i].pop_back();
		// c--;
	// }
	// tmp.push_back(id);
	// temp.push_back(a);
	// st[i].insert(-a);
	
	// while(temp.size())
	// {
		// Q[i].push_back(temp.back());
		// ind[i].push_back(tmp.back());
		// temp.pop_back();
		// tmp.pop_back();
	// }
// }

// void reorder()
// {
	// for(int i=0;i<cnt_blk;i++)
	// {
		// while(Q[i].size()>SQ)
		// {
			// int x=Q[i].back();
			
			// Q[i+1].push_front(x);
			// Q[i].pop_back();
			// st[i+1].insert(-x);
			// st[i].erase(-x);
			// ind[i+1].push_front(ind[i].back());
			// ind[i].pop_back();
		// }
		// while(Q[cnt_blk].size()>0)
			// cnt_blk++;
	// }
// }

// int32_t main()
// {
	// cin>>n;
	// for(int i=1;i<=n;i++)
	// {
		// int a,c;cin>>a>>c;
		// add(a,c,i,cnt_blk-1);
		// if(i%SQ==0)reorder();
	// }
	// for(int i=0;i<cnt_blk;i++)
	// {
		// while(ind[i].size())
		// {
			// cout<<ind[i].front()<<" ";
			// ind[i].pop_front();
		// }
	// }
	// return cout<<endl,0;	
// }


#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int sq = 316;

int n, maxy[2 * sq], sz[2 * sq], ready, go[MAXN];
vector<int> link[2 * sq];

void insert(int id, int v, int u)
{
	link[id].push_back(v);
	int me = sz[id];
	//cout << me << endl;
	while (me && u && (v > link[id][me - 1]))
	{
		u--;
		me--;
		swap(link[id][me], link[id][me + 1]);
	}
	//cout << me << endl;
	sz[id]++;
	maxy[id] = max(maxy[id], v);
	return;
}

void balance() {
	int arr[MAXN], pos = 0;
	for (int i = 0; i <= ready; i++)
	{
		for (int j = sz[i] - 1; ~j; j--)
		{
			arr[pos++] = link[i][j];
		}
		link[i].clear();
	}
	ready = -1;
	int pos2 = 0;
	for (; pos2 != pos; pos2++)
	{
		if (pos2 % sq == 0) {
			if (~ready)
				reverse(link[ready].begin(), link[ready].end());
			ready++;
			maxy[ready] = 0;
			sz[ready] = 0;
		}
		link[ready].push_back(arr[pos2]);
		sz[ready]++;
		maxy[ready] = max(maxy[ready], arr[pos2]);
	}
	reverse(link[ready].begin(), link[ready].end());
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		go[u] = i + 1;
		int id = 0;
		while (id < ready && v > sz[id] && maxy[id] < u)
		{
			v -= sz[id++];
		}
		//cout << id << ' ' << u << ' ' << v << endl;
		insert(id, u, v);
		if (i % sq == 0)
		{
			balance();
		}
	}
	for (int i = ready; ~i; i--)
	{
		for (auto j : link[i])
		{
			cout << go[j] << ' ';
		}
	}
	return 0;
}