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

ll n,m;
ll a[N];
ll tree[4*N];
ll lazy[4*N]={0};

void build(ll node,ll start,ll end){
  if(start==end){ // leaf node
    tree[node]=a[start]; // or tree[node]=a[end] is also correct
  }
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid); // recursion on left child
    build(node*2+1,mid+1,end); // recursion on right child
    tree[node]=min(tree[node*2],tree[node*2+1]); // internal(parent) node values are calculated
  }
}

void range_update(ll node,ll start,ll end,ll left,ll right,ll val,ll x){
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

  if(left<=start && end<=right && tree[node]>x){ // node range is completely within update range
    tree[node]+=(end-start+1)*val;
    if(start!=end){ // not leaf node
      lazy[node*2]+=val; // updating left child
      lazy[node*2+1]+=val; // updating right child
    }
    return;
  }

  if(start==end) return;

  ll mid=(start+end)/2;
  range_update(node*2,start,mid,left,right,val,x);
  range_update(node*2+1,mid+1,end,left,right,val,x);
  tree[node]=min(tree[node*2],tree[node*2+1]); // updating parent node
}

ll range_query(ll node,ll start,ll end,ll left,ll right){
  if(start>end || start>right || end<left){ // node range is completely outside the query range
    return INF;
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
  return min(s1,s2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,0,n) cin>>a[i];

  build(1,0,n-1);

  cin>>m;
  ll x;
  fr(i,0,m){
    cin>>x;
    range_update(1,0,n-1,0,n-1,-1,x);
  }

  fr(i,0,n){
    cout<<range_query(1,0,n-1,i,i)<<" ";
  }

  return 0;
}
