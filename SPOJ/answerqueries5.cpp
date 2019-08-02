#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,a[N];

struct Tree{
  ll sum,ms,mps,mss;
};

struct Tree tree[4*N];

struct Tree merge(struct Tree t1,struct Tree t2){
  struct Tree t;
  t.sum=t1.sum+t2.sum;
  t.mps=max(t1.sum+t2.mps,t1.mps);
  t.mss=max(t2.sum+t1.mss,t2.mss);
  t.ms=MAX(t1.ms,t2.ms,t1.mss+t2.mps);

  return t;
}

void build(ll node,ll start,ll end){
  if(start==end) tree[node].sum=tree[node].ms=tree[node].mps=tree[node].mss=a[start];
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);
    tree[node]=merge(tree[node*2],tree[node*2+1]);
  }
}

struct Tree query(ll node,ll start,ll end,ll l,ll r){
  if(r<start || end<l){
    struct Tree t;
    t.ms=t.mps=t.mss=-INF;
    t.sum=0;
    return t;
  }

  if(l<=start && end<=r) return tree[node];

  ll mid=(start+end)/2;
  struct Tree t1,t2;

  t1=query(node*2,start,mid,l,r);
  t2=query(node*2+1,mid+1,end,l,r);

  return merge(t1,t2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>n;
    fr(i,0,n) cin>>a[i];

    build(1,0,n-1);

    cin>>m;
    ll x1,x2,y1,y2,ans;
    fr(i,0,m){
      cin>>x1>>y1>>x2>>y2;
      x1--;
      x2--;
      y1--;
      y2--;
      if(y1<x2) ans=query(1,0,n-1,x1,y1).mss+query(1,0,n-1,y1+1,x2-1).sum+query(1,0,n-1,x2,y2).mps;
      else {
        ans=query(1,0,n-1,x2,y1).ms;
        ans=max(ans,query(1,0,n-1,x1,x2-1).mss+query(1,0,n-1,x2,y2).mps);
        ans=max(ans,query(1,0,n-1,x1,y1).mss+query(1,0,n-1,y1+1,y2).mps);
      }
      cout<<ans<<"\n";
    }
  }

  return 0;
}
