#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
pii node[N];
vector<ll> adj[N];

bool intersect(pii l,pii r){
	if(l.se<r.fi || l.fi>r.se) return false;
	else return true;
}

void init(){
	fr(i,1,n+1){
		adj[i].clear();
		node[i].fi=INF;
		node[i].se=0;
	}
}

ll dfs(ll v){
	if(!SZ(adj[v])) return 0;

	ll l =adj[v][0];
	ll r=adj[v][1];
	ll lv=dfs(l);
	ll rv=dfs(r);

	if(intersect(node[l],node[r]) || lv==-1 || rv==-1) return -1;

	node[v].fi=min(node[l].fi,node[r].fi);
	node[v].se=max(node[l].se,node[r].se);

	if(node[l].fi>node[r].fi) return lv+rv+1;
	else return lv+rv;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll l,r,ans;
  while(t--){
    cin>>n;

    init();

    fr(i,1,n+1){
    	cin>>l>>r;
    	if(l==-1) node[i].fi=node[i].se=r;
		  else{
        adj[i].PB(l);
			  adj[i].PB(r);
		  }
    }

    ans=dfs(1);
    cout<<ans<<"\n";
  }

  return 0;
}
