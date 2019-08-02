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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

void dijkstras(vector< pair<ll,ll> > edges[],ll n,ll m,ll source_node){
  bool visited[n+1];
  ll dist[n+1];
  fr(i,0,n+1){
    visited[i]=false;
    dist[i]=2e9;
  }
  dist[source_node]=0;

  multiset< pair<ll,ll> > mpq; // min priority queue
  mpq.insert(MP(dist[source_node],source_node));

  pair<ll,ll> p;
  ll current_node,edge_weight,neighbour_node;
  while(!mpq.empty()){
    p=*mpq.begin();
    mpq.erase(mpq.begin());
    current_node=p.second;
    if(visited[current_node]==false){ // if node is not visited till now
      visited[current_node]=true;
      fr(i,0,edges[current_node].size()){ // all the neighbour nodes distance is updated
        neighbour_node=edges[current_node][i].second;
        edge_weight=edges[current_node][i].first;
        if(dist[current_node]+edge_weight<dist[neighbour_node]){
          dist[neighbour_node]=dist[current_node]+edge_weight;
          mpq.insert(MP(dist[neighbour_node],neighbour_node)); // pushed into min priority queue
        }
      }
    }
  }

  fr(i,1,n+1){
    if(dist[i]==INF) cout<<i<<" "<<-1<<"\n";
    else cout<<i<<" "<<dist[i]<<"\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,s,d,c1,c2,d1,d2,w1,w2,w3;
  cin>>n>>s>>d>>c1>>c2>>d1>>d2>>w1>>w2>>w3;

  ll m=0;
  vector< pair<ll,ll> > edges[N];
  ll start_node,end_node,weight;
  ll deg;

  fr(i,1,n+1){
    deg=((i*c2)+(i*i*d2))%d;
    start_node=i;
    fr(j,1,deg+1){
      end_node=((i*c1)+(j*d1))%n;
      end_node+=1;
      weight=((i*w1)+(j*w2))%w3;
      edges[start_node].PB(MP(weight,end_node));
      m++;
    }
  }

  dijkstras(edges,n,m,s);

  return 0;
}
