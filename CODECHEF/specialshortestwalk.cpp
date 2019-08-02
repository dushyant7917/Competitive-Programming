#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e16
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))
#define pp pair<pii,pii>

ll n,m;
vector<pii> large[N],small[N];
ll src,dst;
ll dist[N],s[N],l[N];

void init(){
  fr(i,1,n+1){
    small[i].clear();
    large[i].clear();
    s[i]=l[i]=0;
    dist[i]=INF;
  }
}

void dijkstras(){
  priority_queue<pp,vector<pp>,greater<pp> > pq;
  pq.push(MP(MP(0,0),MP(0,src)));
  dist[0]=0;

  ll len,cnt,prv,w,u,v,ind;
  while(SZ(pq)){
    len=pq.top().fi.fi;
    cnt=pq.top().fi.se;
    prv=pq.top().se.fi;
    u=pq.top().se.se;
    pq.pop();
    dist[u]=min(dist[u],len);

    if(cnt&1){
      fr(i,s[u],SZ(small[u])){
        s[u]=i;
        v=small[u][i].se;
        w=small[u][i].fi;
        if(w<prv) pq.push(MP(MP(len+w,0),MP(w,v)));
        else break;
      }
    }

    else{
      fr(i,l[u],SZ(large[u])){
        l[u]=i;
        v=large[u][i].se;
        w=-large[u][i].fi;
        if(w>prv) pq.push(MP(MP(len+w,1),MP(w,v)));
        else break;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>n>>m;

    init();

    ll u,v,w;
    fr(i,0,m){
      cin>>u>>v>>w;
      small[u].PB(MP(w,v));
      small[v].PB(MP(w,u));
      large[u].PB(MP(-w,v));
      large[v].PB(MP(-w,u));
    }

    cin>>src>>dst;

    fr(i,1,n+1){
      sort(small[i].begin(),small[i].end());
      sort(large[i].begin(),large[i].end());
    }

    dijkstras();

    if(dist[dst]!=INF) cout<<dist[dst]<<"\n";
    else cout<<"No Solution\n";
  }

  return 0;
}
