#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 200002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
int a[N];
ll f[1000001];
ll ans;
int block_size;

struct Query{
  int l; // left
  int r; // right
  int ind;
};

struct Query q[N];
ll result[N];

inline bool cmp(struct Query q1,struct Query q2){
  if(q1.l/block_size!=q2.l/block_size)
    return (q1.l/block_size < q2.l/block_size);

  else return (q1.r < q2.r);
}

inline void add(int ind){
  ans-=f[a[ind]]*f[a[ind]]*a[ind];
  f[a[ind]]++;
  ans+=f[a[ind]]*f[a[ind]]*a[ind];
}

inline void del(int ind){
  ans-=f[a[ind]]*f[a[ind]]*a[ind];
  f[a[ind]]--;
  ans+=f[a[ind]]*f[a[ind]]*a[ind];
}

inline void process(){
  int l,r;

  l=1;
  r=0;
  ans=0ll;

  MS(f,0ll);

  fr(i,1,m+1){

    while(r<q[i].r){
      r++;
      add(r);
    }

    while(r>q[i].r){
      del(r);
      r--;
    }

    while(l<q[i].l){
      del(l);
      l++;
    }

    while(l>q[i].l){
      l--;
      add(l);
    }

    result[q[i].ind]=ans;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  for(int i=1;i<n+1;++i) cin>>a[i];

  block_size=sqrt(n);

  int a,b;
  for(int i=1;i<m+1;++i){
    cin>>a>>b;
    q[i].l=a;
    q[i].r=b;
    q[i].ind=i;
  }

  sort(q+1,q+1+m,cmp);

  process();

  for(int i=1;i<m+1;++i){
    cout<<result[i]<<"\n";
  }

  return 0;
}
