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
#define N 100005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll a[N];

struct Tree{
  ll mf; // max frequency
  ll mpf; // max prefix frequency
  ll msf; // max suffix frequency
};

Tree tree[4*N];

Tree merge(Tree t1,Tree t2,ll start,ll end,ll mid){
  Tree t;

  t.mf=max(t1.mf,t2.mf);
  t.mpf=t1.mpf;
  t.msf=t2.msf;

  if(a[mid]==a[mid+1]){
    t.mf=max(t.mf,t1.msf+t2.mpf);
    if(a[start]==a[mid]) t.mpf+=t2.mpf;
    if(a[mid+1]==a[end]) t.msf+=t1.msf;
  }

  return t;
}

void build(ll node,ll start,ll end){
  if(start==end){ // leaf node
    tree[node].mf=tree[node].mpf=tree[node].msf=1;
  }
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid); // recursion on left child
    build(node*2+1,mid+1,end); // recursion on right child
    tree[node]=merge(tree[node*2],tree[node*2+1],start,end,mid); // internal(parent) node values are calculated
  }
}

Tree query(ll node,ll start,ll end,ll left,ll right){
  if(right<start || end<left){ // node range is completely outside the query range
    Tree t;
    t.mf=t.mpf=t.msf=0;
    return t;
  }
  if(left<=start && end<=right){ // node range is completely inside query range
    return tree[node];
  }
  ll mid=(start+end)/2;
  Tree t1=query(node*2,start,mid,left,right);
  Tree t2=query(node*2+1,mid+1,end,left,right);
  return merge(t1,t2,start,end,mid);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m,l,r;
  while(cin>>n && n){
    cin>>m;

    fr(i,0,n) cin>>a[i];

    build(1,0,n-1);

    fr(i,0,m){
      cin>>l>>r;
      l--;
      r--;
      cout<<query(1,0,n-1,l,r).mf<<"\n";
    }
  }

  return 0;
}
