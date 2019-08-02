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
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n,k;
ll a[N],ans[N];

struct Tree{
  ll min_val;
  ll max_val;
  ll or_val;
  ll and_val;
  ll cost;
};

struct Tree tree[4*N];
struct Tree lazy[2*N];

void build(ll node,ll start,ll end){
  if(start==end){ // leaf node
    tree[node].min_val=tree[node].max_val=tree[node].or_val=tree[node].and_val=a[start]; // or tree[node]=a[end] is also correct
    tree[node].cost=0;
  }
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid); // recursion on left child
    build(node*2+1,mid+1,end); // recursion on right child
    tree[node].min_val=min(tree[node*2].min_val,tree[node*2+1].min_val); // internal(parent) node values are calculated
    tree[node].max_val=max(tree[node*2].max_val,tree[node*2+1].max_val); // internal(parent) node values are calculated
    tree[node].or_val=(tree[node*2].or_val|tree[node*2+1].or_val); // internal(parent) node values are calculated
    tree[node].and_val=(tree[node*2].and_val&tree[node*2+1].and_val); // internal(parent) node values are calculated
    tree[node].cost=(tree[node].or_val-tree[node].and_val)-(tree[node].max_val-tree[node].min_val); // internal(parent) node values are calculated
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

  cin>>n>>k;
  fr(i,0,n) cin>>a[i],ans[i]=-1;

  build(1,0,n-1); // constructing the segment tree

  cout<<range_query(1,0,n-1,0,0)<<"\n"; // a[0...0]
  cout<<range_query(1,0,n-1,0,1)<<"\n"; // a[0...1]
  cout<<range_query(1,0,n-1,0,2)<<"\n"; // a[0...2]
  cout<<range_query(1,0,n-1,0,3)<<"\n"; // a[0...3]
  cout<<range_query(1,0,n-1,2,2)<<"\n"; // a[2...2]
  cout<<range_query(1,0,n-1,1,3)<<"\n"; // a[1...3]

  range_update(1,0,n-1,0,3,10); // a[0]=10

  cout<<range_query(1,0,n-1,0,0)<<"\n"; // a[0...0]
  cout<<range_query(1,0,n-1,0,1)<<"\n"; // a[0...1]
  cout<<range_query(1,0,n-1,0,2)<<"\n"; // a[0...2]
  cout<<range_query(1,0,n-1,0,3)<<"\n"; // a[0...3]
  cout<<range_query(1,0,n-1,2,2)<<"\n"; // a[2...2]
  cout<<range_query(1,0,n-1,1,3)<<"\n"; // a[1...3]

  range_update(1,0,n-1,2,2,-10); // a[0]=-10

  cout<<range_query(1,0,n-1,2,3)<<"\n"; // a[2...3]

  return 0;
}
