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

bool bank[N];
bool visited[N];
bool bo[N];
ll dist[N];

void bank_init(ll n){
  fr(i,1,n+1){
    bank[i]=false;
  }
}

void bo_init(ll n){
  fr(i,1,n+1){
    bo[i]=false;
  }
}

void visit_init(ll n){
  fr(i,1,n+1){
    visited[i]=false;
  }
}

void dfs(vector<ll> graph[],ll node,ll d){
  visited[node]=true;

  if(bank[node]==true) bo[node]=true;
  fr(i,0,graph[node].size()){
    if(!visited[graph[node][i]]){
      if(bo[node]==true) bo[graph[node][i]]=true;
      dfs(graph,graph[node][i],d+1);
    }
  }
  dist[node]=d;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,m,u,v,ty,c;
  while(t--){
    cin>>n>>m;

    bank_init(n);

    vector<ll> graph[n+1];
    fr(i,0,n-1){
      cin>>u>>v;
      graph[u].PB(v);
      graph[v].PB(u);
    }

    fr(i,0,m){
      cin>>ty>>c;
      if(ty==1){
        bank[c]=true;
      }
      else{
        bo_init(n);
        visit_init(n);
        dfs(graph,c,0);
        vector<ll> cities;
        fr(i,1,n+1){
          if(bo[i]){
            cities.PB(i);
          }
        }
        if(cities.size()<2) cout<<-1;
        else cout<<cities[cities.size()-2];
        cout<<"\n";
      }
    }
  }

  return 0;
}
