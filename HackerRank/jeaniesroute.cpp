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

ll max_len;
ll n,k;

ll component[1000001];

void initialize(ll n){
  fr(i,0,n+1){
    component[i]=i;
  }
}

ll find_component(ll node){
  while(component[node]!=node){
    component[node]=component[component[node]];
    node=component[node];
  }
  return node;
}

void union_components(ll node1,ll node2){
  ll x=find_component(node1);
  ll y=find_component(node2);
  component[x]=component[y];
}

ll kruskals(pair<ll, pair<ll,ll> > edges[],ll m){
  ll node1,node2,weight;
  ll cost=0;
  fr(i,0,m){
    node1=edges[i].second.first;
    node2=edges[i].second.second;
    weight=edges[i].first;
    if(find_component(node1)!=find_component(node2)){
      cost+=weight;
      union_components(node1,node2);
    }
  }
  return cost;
}

void dfs(vector< pair<ll,ll> > graph[],ll source,ll prv_len,bool visited[]){
  visited[source]=true;
  ll cur_len=0;
  pair<ll,ll> p;
  fr(i,0,graph[source].size()){
    p=graph[source][i];
    if(visited[p.first]==false){
      cur_len=prv_len+p.second;
      dfs(graph,p.first,cur_len,visited);
    }
    if(cur_len>max_len) max_len=cur_len;
    cur_len=0;
  }
}

ll longest_path(vector< pair<ll,ll> > graph[],ll n){
  max_len=-INF;
  fr(i,1,n+1){
    bool visited[n+1];
    fr(j,1,n+1) visited[j]=false;
    dfs(graph,i,0,visited);
  }
  return max_len;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n>>k;
  initialize(n);

  pair<ll, pair<ll,ll> > edges[n-1];
  vector< pair<ll,ll> > graph[n+1];

  ll a[k];
  map<ll,ll> kmap;
  fr(i,0,k){
    cin>>a[i];
    kmap[a[i]]++;
  }


  ll edge[n-1][3];
  map<ll,ll> degree;

  ll u,v,d;
  fr(i,0,n-1){
    cin>>u>>v>>d;
    degree[u]++; degree[v]++;
    edge[i][0]=u; edge[i][1]=v; edge[i][2]=d;
  }
  ll index=0;
  fr(i,0,n-1){
    if((degree[edge[i][0]]==1 && kmap[edge[i][0]]==0) || (degree[edge[i][1]]==1 && kmap[edge[i][1]]==0)) {}//don't make edge
    else {
      edges[index++]=MP(edge[i][2],MP(edge[i][0],edge[i][1]));
      graph[edge[i][0]].PB(MP(edge[i][1],edge[i][2]));
      graph[edge[i][1]].PB(MP(edge[i][0],edge[i][2]));
    }
  }

  sort(edges,edges+index);

  cout<<(2*kruskals(edges,index))-longest_path(graph,n);

  return 0;
}
