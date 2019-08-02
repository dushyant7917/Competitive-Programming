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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,k,a[N],tree[4*N];

void build(ll node,ll start,ll end){
  if(start==end) tree[node]=a[start];
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);
    tree[node]=tree[node*2]&tree[node*2+1];
  }
}

ll query(ll node,ll start,ll end,ll l,ll r){
  if(r<start || end<l) return (1<<31)-1ll;

  if(l<=start && end<=r) return tree[node];

  ll mid=(start+end)/2;
  ll q1=query(node*2,start,mid,l,r);
  ll q2=query(node*2+1,mid+1,end,l,r);

  return (q1&q2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>n>>k;
    fr(i,0,n) cin>>a[i];

    build(1,0,n-1);

    k=min(k,n-1);

    ll ans;

    fr(i,0,n){
      if(0<=i-k && i+k<=n-1) ans=query(1,0,n-1,i-k,i+k);
      else if(0>i-k && i+k<=n-1){
        ans=query(1,0,n-1,0,i+k);
        ans&=query(1,0,n-1,n-(k-i),n-1);
      }
      else if(0<=i-k && i+k>n-1){
        ans=query(1,0,n-1,i-k,n-1);
        ans&=query(1,0,n-1,0,(k+i)-n);
      }
      else{
        ans=query(1,0,n-1,i-k,i+k);
        ans&=query(1,0,n-1,n-(k-i),n-1);
        ans&=query(1,0,n-1,0,(k+i)-n);
      }
      cout<<ans<<" ";
    }

    cout<<"\n";
  }

  return 0;
}
