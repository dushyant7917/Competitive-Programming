#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll MAX9(ll n1,ll n2,ll n3,ll n4,ll n5,ll n6,ll n7,ll n8,ll n9){
  ll ans=-INF;

  ans=MAX(ans,n1,n2);
  ans=MAX(ans,n3,n4);
  ans=MAX(ans,n5,n6);
  ans=MAX(ans,n7,n8);
  ans=max(ans,n9);

  return ans;
}

ll a[2*N];

struct Tree{
  ll l,r;
  ll mxp,mxs,mx,sum;
};

Tree tree[8*N];

void build(ll node,ll start,ll end){
  if(start==end){
    tree[node].l=tree[node].r=start;
    tree[node].sum=tree[node].mxp=tree[node].mxs=tree[node].mx=a[start];
  }

  else{
    ll mid=(start+end)/2;

    build(node*2,start,mid);
    build(node*2+1,mid+1,end);

    tree[node].l=min(tree[node*2].l,tree[node*2+1].l);
    tree[node].r=max(tree[node*2].r,tree[node*2+1].r);

    tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;

    if(tree[node*2].sum==tree[node*2].r-tree[node*2].l+1){
      tree[node].mxp=tree[node*2].sum;
      if(tree[node*2+1].mxp>0) tree[node].mxp+=tree[node*2+1].mxp;
    }
    else tree[node].mxp=tree[node*2].mxp;

    if(tree[node*2+1].sum==tree[node*2+1].r-tree[node*2+1].l+1){
      tree[node].mxs=tree[node*2+1].sum;
      if(tree[node*2].mxs>0) tree[node].mxs+=tree[node*2].mxs;
    }
    else tree[node].mxs=tree[node*2+1].mxs;

    tree[node].mx=MAX9(tree[node].mxp,tree[node].mxs,tree[node*2].mx,tree[node*2+1].mx,tree[node*2].mxs+tree[node*2+1].mxp,tree[node*2].mxp,tree[node*2+1].mxp,tree[node*2].mxs,tree[node*2+1].mxs);
  }
}

Tree query(ll node,ll start,ll end,ll left,ll right){
  if(right<start || end<left){
    Tree t;
    t.l=INF;
    t.r=-INF;
    t.sum=0;
    t.mx=t.mxp=t.mxs=-INF;
    return t;
  }

  if(left<=start && end<=right){
    return tree[node];
  }

  ll mid=(start+end)/2;
  Tree t1=query(node*2,start,mid,left,right);
  Tree t2=query(node*2+1,mid+1,end,left,right);

  Tree t;

  t.l=min(t1.l,t2.l);
  t.r=max(t1.r,t2.r);

  t.sum=t1.sum+t2.sum;

  if(t1.sum==t1.r-t1.l+1ll){
    t.mxp=t1.sum;
    if(t2.mxp>0) t.mxp+=t2.mxp;
  }
  else t.mxp=t1.mxp;

  if(t2.sum==t2.r-t2.l+1ll){
    t.mxs=t2.sum;
    if(t1.mxs>0) t.mxs+=t1.mxs;
  }
  else t.mxs=t2.mxs;

  t.mx=MAX9(t.mxp,t.mxs,t1.mx,t2.mx,t1.mxs+t2.mxp,t1.mxp,t2.mxp,t1.mxs,t2.mxs);

  return t;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,q,k;
  cin>>n>>q>>k;

  fr(i,0,n) cin>>a[i];
  fr(i,n,2*n) a[i]=a[i-n];

  build(1,0,2*n-1);

  string s;
  cin>>s;

  ll rot=0,ind;

  fr(i,0,SZ(s)){
    if(s[i]=='!'){
      rot++;
      rot%=n;
    }

    else{
      ind=(n-rot)%n;
      cout<<min(k,query(1,0,2*n-1,ind,ind+n-1).mx)<<"\n";
    }
  }

  return 0;
}
