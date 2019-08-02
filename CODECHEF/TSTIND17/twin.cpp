#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 20001
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001

ll n,m;
bool visited[N];
ll skill[N];
vector<ll> graph[N];
ll sum[N];
ll pos[N];
ll beg[N];
ll fin[N];
ll ind=0;

void init(){
  fr(i,1,n+1){
    visited[i]=false;
    sum[i]=0;
  }
}

void dfs(ll node) {
  visited[node]=1;
  pos[node]=++ind;

  fr(i,0,graph[node].size()){
    if(!visited[graph[node][i]]){
      dfs(graph[node][i]);
    }
  }

  beg[node]=pos[node];
  fin[node]=ind;
}

void update(ll pos,ll val){
  while(pos<=n){
    sum[pos]+=val;
    pos+=(pos)&(-pos);
  }
}

ll query(ll pos){
  ll ans=0;
  while(pos>0){
    ans+=sum[pos];
    pos-=(pos)&(-pos);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  fr(i,1,n+1) cin>>skill[i];

  ll u,v;
  fr(i,0,n-1){
    cin>>u>>v;
    graph[u].PB(v);
    graph[v].PB(u);
  }

  init();
  dfs(1);

  fr(i,1,n+1){
    update(pos[i],skill[i]);
  }

  string c;
  ll s,x;
  fr(i,0,m){
    cin>>c>>s;
    if(c[0]=='Q'){
      cout<<query(fin[s])-query(beg[s]-1)<<"\n";
    }
    else{
      cin>>x;
      update(pos[s],x-skill[s]);
      skill[s]=x;
    }
  }

  return 0;
}
