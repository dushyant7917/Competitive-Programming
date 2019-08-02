#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
ll a[N];
ll block_size;
ll ans=0;
map<ll,ll> cnt;
map<ll,ll> duplicate;

struct Query{
  ll l;
  ll r;
  ll ind;
  ll ans;
};

bool cmp_block(struct Query q1,struct Query q2){
  if(q1.l/block_size!=q2.l/block_size) return q1.l/block_size < q2.l/block_size;
  else return q1.r<q2.r;
}

bool cmp_ind(struct Query q1,struct Query q2){
  return q1.ind<q2.ind;
}

void ADD(ll ind){
  cnt[a[ind]]++;
  if(cnt[a[ind]]==1) ans++;
  if(cnt[a[ind]]==2){
    ans--;
    duplicate[a[ind]]=1;
  }
}

void DEL(ll ind){
  cnt[a[ind]]--;
  if(cnt[a[ind]]==1 && duplicate[a[ind]]==1){
    ans++;
    duplicate[a[ind]]=0;
  }
  if(cnt[a[ind]]==0 && duplicate[a[ind]]==0) ans--;
  if(cnt[a[ind]]==0 && duplicate[a[ind]]==1) duplicate[a[ind]]=0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  block_size=sqrt(n);
  fr(i,0,n) cin>>a[i];

  cin>>m;
  struct Query q[m];
  ll l,r;
  fr(i,0,m){
    cin>>l>>r;
    q[i].ind=i;
    q[i].l=l-1;
    q[i].r=r-1;
  }

  sort(q,q+m,cmp_block);

  ll L,R;
  l=r=0;

  fr(i,0,m){
    L=q[i].l;
    R=q[i].r;

    while(l<L){
      DEL(l);
      l++;
    }
    while(l>L){
      ADD(l-1);
      l--;
    }
    while(r<=R){
      ADD(r);
      r++;
    }
    while(r>R+1){
      DEL(r-1);
      r--;
    }

    q[i].ans=ans;
  }

  sort(q,q+m,cmp_ind);

  fr(i,0,m) cout<<q[i].ans<<"\n";

  return 0;
}
