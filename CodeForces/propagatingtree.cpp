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
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n,m;

ll a[N];
ll pos[N];
ll beg[N];
ll fin[N];
ll level[N];
ll tree[4*N];
ll lazy[4*N]={0};
ll visited[N]={0};

vector<ll> graph[N];

ll timer=-1;

void dfs(ll node,ll lev){
  ++timer;
  pos[node]=timer;
  level[node]=lev%2;
  visited[node]=1;

  fr(i,0,graph[node].size()){
    if(!visited[graph[node][i]]){
      dfs(graph[node][i],lev+1);
    }
  }

  beg[node]=pos[node];
  fin[node]=timer;
}

void build(ll node,ll start,ll end){
  if(start==end){ // leaf node
    tree[node]=a[start]; // or tree[node]=a[end] is also correct
  }
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid); // recursion on left child
    build(node*2+1,mid+1,end); // recursion on right child
    tree[node]=tree[node*2]+tree[node*2+1]; // internal(parent) node values are calculated
  }
}

void range_update(ll node,ll start,ll end,ll left,ll right,ll val,ll lev){
  if(lazy[node]!=0){ // node needs to be updated
    tree[node]+=(end-start+1)*lazy[node];
    if(start!=end){ // not leaf node
      lazy[node*2]+=lazy[node]; // making left child as lazy
      lazy[node*2+1]+=lazy[node]; // making right child as lazy
    }
    lazy[node]=0; // node is no longer lazy
  }

  if(end<start || start>right || end<left){ // node range is completely outside the update range
    return;
  }

  if(left<=start && end<=right){ // node range is completely within update range
    if(level[node]==lev){
      tree[node]+=(end-start+1)*val;
      if(start!=end){ // not leaf node
        lazy[node*2]+=val; // updating left child
        lazy[node*2+1]+=val; // updating right child
      }
    }
    else{
      tree[node]-=(end-start+1)*val;
      if(start!=end){ // not leaf node
        lazy[node*2]-=val; // updating left child
        lazy[node*2+1]-=val; // updating right child
      }
    }
    return;
  }

  ll mid=(start+end)/2;
  range_update(node*2,start,mid,left,right,val,lev);
  range_update(node*2+1,mid+1,end,left,right,val,lev);
  tree[node]=tree[node*2]+tree[node*2+1]; // updating parent node
}


ll range_query(ll node,ll start,ll end,ll left,ll right){
  if(start>end || start>right || end<left){ // node range is completely outside the query range
    return 0;
  }

  if(lazy[node]!=0){ // node needs to be updated
    tree[node]+=(end-start+1)*lazy[node];
    if(start!=end){ // not a leaf node
      lazy[node*2]+=lazy[node]; // making left child as lazy
      lazy[node*2+1]+=lazy[node]; // making right child as lazy
    }
    lazy[node]=0; // node is no longer lazy
  }

  if(left<=start && end<=right){ // node range is completely within update range
    return tree[node];
  }

  ll mid=(start+end)/2;
  ll s1=range_query(node*2,start,mid,left,right);
  ll s2=range_query(node*2+1,mid+1,end,left,right);
  return (s1+s2);
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  fr(i,0,n) cin>>a[i];

  ll u,v;
  fr(i,0,n-1){
    cin>>u>>v;
    graph[u-1].PB(v-1);
    graph[v-1].PB(u-1);
  }

  dfs(0,0);

  build(1,0,n-1);

  ll ty,x,val;
  fr(i,0,m){
    cin>>ty;
    if(ty==1){
      cin>>x>>val;
      range_update(1,0,n-1,beg[x-1],fin[x-1],val,level[x-1]);
    }
    else{
      cin>>x;
      cout<<range_query(1,0,n-1,beg[x-1],beg[x-1])<<"\n";
    }
  }

  return 0;
}
