#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000000
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll a[N];
ll tree[4*N][2];
ll lazy[4*N][2]={0};
map<ll,ll> f;

void cal(){
  f[1]=1;
  fr(i,2,N) f[i]=f[i-1]*i;
}

void build(ll node,ll start,ll end){
  if(start==end){ // leaf node
    tree[node][0]=a[start]; // or tree[node]=a[end] is also correct
    tree[node][1]=f[tree[node][0]];
  }
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid); // recursion on left child
    build(node*2+1,mid+1,end); // recursion on right child
    tree[node][0]=tree[node*2][0]+tree[node*2+1][0]; // internal(parent) node values are calculated
    tree[node][1]=f[tree[node][0]];
  }
}

void range_update(ll node,ll start,ll end,ll left,ll right,ll val){
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
    tree[node]+=(end-start+1)*val;
    if(start!=end){ // not leaf node
      lazy[node*2]+=val; // updating left child
      lazy[node*2+1]+=val; // updating right child
    }
    return;
  }

  ll mid=(start+end)/2;
  range_update(node*2,start,mid,left,right,val);
  range_update(node*2+1,mid+1,end,left,right,val);
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
    return f[tree[node]];
  }

  ll mid=(start+end)/2;
  ll s1=range_query(node*2,start,mid,left,right);
  ll s2=range_query(node*2+1,mid+1,end,left,right);
  return (f[s1]+f[s2]);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cal();

  ll n,m;
  cin>>n>>m;

  fr(i,0,n) cin>>a[i];

  build(1,0,n-1); // constructing the segment tree

  //cout<<range_query(1,0,n-1,0,0)<<"\n"; // a[0...0]
  //cout<<range_query(1,0,n-1,0,3)<<"\n"; // a[0...3]

  //range_update(1,0,n-1,0,3,10); // a[0]=10

  //range_update(1,0,n-1,2,2,-10); // a[0]=-10

  return 0;
}
