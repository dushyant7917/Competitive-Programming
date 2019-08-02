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

ll visited[1001];
ll n,m,s;

void bfs(vector<ll> graph[], ll start_node, ll dist[]) {
  fr(i,0,1000) visited[i]=0;
  queue<ll> q;
  visited[start_node]=1;
  q.push(start_node);

  ll node;
  while(q.empty()==false) {
    node=q.front();
    q.pop();

    for(ll i=0;i<graph[node].size();i++) {
      if(visited[graph[node][i]]==0) {
        visited[graph[node][i]]=1;
        q.push(graph[node][i]);
        dist[graph[node][i]]=dist[node]+6;
      }
    }
  }

  fr(i,1,n+1){
    if(i!=start_node){
      if(dist[i]==0) cout<<-1<<" ";
      else cout<<dist[i]<<" ";
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    cin>>n>>m;

    vector<ll> edges[n+1];
    ll a,b,weight=6;
    fr(i,0,m){
      cin>>a>>b;
      edges[a].PB(b);
      edges[b].PB(a);
    }

    ll dist[n+1]={0};
    cin>>s;
    dist[s]=0;
    bfs(edges,s,dist);

    cout<<"\n";
  }

  return 0;
}
