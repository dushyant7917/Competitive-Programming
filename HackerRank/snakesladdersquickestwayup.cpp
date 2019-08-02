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

ll n,m;
ll s,e; // start and end nodes for ladders and snakes

ll actual_node[101];
bool visited[101];
ll dist[101];
vector< pair<ll,ll> > edges[101];

void initialize(){
  fr(i,1,101){
    visited[i]=false;
    actual_node[i]=i;
    dist[i]=INF;
  }
  fr(i,1,100){
    for(ll j=i+1;j<=i+6 && j<=100;j++){
      edges[i].PB(MP(1,j));
    }
  }
}

void dijkstras(ll source_node=1){
  source_node=actual_node[source_node];
  dist[source_node]=0;

  multiset< pair<ll,ll> > mpq; // min priority queue
  mpq.insert(MP(dist[source_node],source_node));

  pair<ll,ll> p;
  ll current_node,edge_weight,neighbour_node;
  while(!mpq.empty()){
    p=*mpq.begin();
    mpq.erase(mpq.begin());
    current_node=actual_node[p.second];
    if(visited[current_node]==false){ // if node is not visited till now
      visited[current_node]=true;
      fr(i,0,edges[current_node].size()){ // all the neighbour nodes distance is updated
        neighbour_node=actual_node[edges[current_node][i].second];
        edge_weight=edges[current_node][i].first;
        if(dist[current_node]+edge_weight<dist[neighbour_node]){
          dist[neighbour_node]=dist[current_node]+edge_weight;
          mpq.insert(make_pair(dist[neighbour_node],neighbour_node)); // pushed into min priority queue
        }
      }
    }
  }

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  while(t--){
    initialize();

    cin>>n;
    fr(i,0,n){
      cin>>s>>e;
      actual_node[s]=e;
    }
    cin>>m;
    fr(i,0,m){
      cin>>s>>e;
      actual_node[s]=e;
    }

    dijkstras();

    if(dist[100]!=INF) cout<<dist[100]<<"\n";
    else cout<<-1<<"\n";
    fr(i,0,101) edges[i].clear();
  }

  return 0;
}
