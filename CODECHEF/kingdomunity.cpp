#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9

ll n,m,k;

ll t=0; // time
bool visited[3000];
ll parent[3000];
ll cnt=0;
set<ll> ap;

void dfs(ll v,vector<ll> adj[],ll low_time[],ll disc_time[]){
  visited[v]=true;
  low_time[v]=disc_time[v]=t+1;
  ll child=0;
  fr(i,0,adj[v].size()){
    if(visited[adj[v][i]]==false){
      child++;
      parent[adj[v][i]]=v;
      t++;
      dfs(adj[v][i],adj,low_time,disc_time);
      low_time[v]=min(low_time[v],low_time[adj[v][i]]);

      if(parent[v]==-1 && child>1) ap.insert(v);

      if(parent[v]!=-1 && low_time[adj[v][i]]>=disc_time[v]) ap.insert(v);

    }
    else{
      if(parent[v]!=adj[v][i]) low_time[v]=min(low_time[v],disc_time[adj[v][i]]);
    }
  }
}

void initialize(){
  fr(i,0,n){
    visited[i]=false;
    parent[i]=-1;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>n>>m>>k;
    vector<ll> adj[n];

    ll a,b;
    fr(i,0,m){
      cin>>a>>b;
      adj[a].PB(b);
      adj[b].PB(a);
    }

    ll low_time[n],disc_time[n];
    initialize();
    dfs(0,adj,low_time,disc_time);
    cout<<ap.size()*k<<"\n";
    ap.clear();
  }

  return 0;
}
