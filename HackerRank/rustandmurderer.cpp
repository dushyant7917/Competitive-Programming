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

ll n,m,s;
ll u,v;

void bfs_0_1(vector< pair<ll,ll> > nodes[],ll start,ll dist[]){
  fr(i,1,n+1) dist[i]=INF;
  deque<ll> dq;
  dq.PB(start);
  dist[start]=0;

  ll node;
  while(!dq.empty()){
    node=dq.front();
    dq.pop_front();
    fr(i,0,nodes[node].size()){
      if(dist[node]+nodes[node][i].second<dist[nodes[node][i].first]){
        dist[nodes[node][i].first]=dist[node]+nodes[node][i].second;
        if(nodes[node][i].second==1) dq.PB(nodes[node][i].first);
        else dq.push_front(nodes[node][i].first);
      }
    }
  }

  fr(i,1,n+1){
    if(i!=start) cout<<dist[i]<<" ";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>n>>m;

    vector< pair<ll,ll> > nodes[n+1];
    ll dist[n+1];

    ll am[n+1][n+1];
    fr(i,1,n+1) fr(j,1,n+1){
      if(i==j) am[i][j]=0;
      else am[i][j]=1;
    }

    fr(i,0,m){
      cin>>u>>v;
      am[u][v]=0;
      am[v][u]=0;
    }

    fr(i,1,n+1) fr(j,1,n+1) {
      if(am[i][j]==1){
        nodes[i].PB(MP(j,1));
        nodes[j].PB(MP(i,1));
      }
    }

    cin>>s;
    bfs_0_1(nodes,s,dist);
    cout<<"\n";
  }

  return 0;
}
