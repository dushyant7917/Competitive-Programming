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

ll a[N];
ll tree[4*N];

void build(ll node,ll start,ll end){
  if(start==end){ // leaf node
    tree[node]=a[start]; // or tree[node]=a[end] is also correct
  }
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid); // recursion on left child
    build(node*2+1,mid+1,end); // recursion on right child
    tree[node]=tree[node*2]^tree[node*2+1]; // internal(parent) node values are calculated
  }
}

void update(ll node,ll start,ll end,ll pos,ll val){
  if(start==end){ // leaf node
    a[pos]=val;
    tree[node]=val;
  }
  else{
    ll mid=(start+end)/2;
    if(start<=pos && pos<=mid){ // pos is in left child of node
      update(node*2,start,mid,pos,val);
    }
    else{ // pos is in right child of node
      update(node*2+1,mid+1,end,pos,val);
    }
    tree[node]=tree[node*2]^tree[node*2+1]; // internal(parent) node values are updated
  }
}

ll query(ll node,ll start,ll end,ll left,ll right,ll k){
  if(right<start || end<left){ // node range is completely outside the query range
    return 0;
  }
  if(left<=start && end<=right){ // node range is completely inside query range
    return tree[node];
  }
  ll mid=(start+end)/2;
  ll s1=query(node*2,start,mid,left,right,k);
  ll s2=query(node*2+1,mid+1,end,left,right,k);
  return (s1+s2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,q;
  cin>>n>>q;

  fr(i,0,n) cin>>a[i];

  build(1,0,n-1); // constructing the segment tree

  fr(i,1,2*n){
    cout<<i<<":"<<tree[i]<<"\n";
  }
  ll z=0;
  fr(i,0,n){
    z=z^a[i];
    cout<<z<<" ";
  }
  cout<<"\n";

  ll t,i,x,k;
  fr(j,0,q){
    cin>>t;
    if(t==1){
      cin>>i>>x;
      update(1,0,n-1,i-1,x);
      fr(i,1,2*n){
        cout<<i<<":"<<tree[i]<<"\n";
      }
      z=0;
      fr(i,0,n){
        z=z^a[i];
        cout<<z<<" ";
      }
      cout<<"\n";
    }
    else{
      cin>>i>>k;
      cout<<query(1,0,n-1,0,i-1,k)<<"\n";
    }
  }

  return 0;
}
