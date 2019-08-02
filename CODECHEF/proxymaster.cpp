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

ll n,q;
ll a[N];
ll tree[2*N][2];
ll prime[N];
ll sdp[N]={0};

struct Query{
  ll l;
  ll r;
  ll k;
  ll id;
  ll ans;
};

bool cmp(struct Query q1,struct Query q2){
  return q1.k<q2.k;
}

bool cmp2(struct Query q1,struct Query q2){
  return q1.id<q2.id;
}

void sieve(ll mv){
  memset(prime,1,sizeof(prime));

  for(ll i=2;i<=mv;i++){
    if(prime[i]){
      sdp[i]+=i;
      for(ll j=2*i;j<=mv;j=j+i){
        prime[j]=0;
        sdp[j]+=i;
      }
    }
  }
}

void build(){
  fr(i,n,2*n){
    tree[i][0]=sdp[a[i-n]];
    tree[i][1]=sdp[a[i-n]]*(i-n+1);
  }

  for(ll i=n-1;i>=0;i--){
    tree[i][0]=tree[i*2][0]+tree[i*2+1][0];
    tree[i][1]=tree[i*2][1]+tree[i*2+1][1];
  }
}

void update(ll l,ll r,ll k){
  l+=n;
  r+=n;

  while(l<r){
    if(l&1){
      if(tree[l][0]<=k){
        tree[l][0]=tree[l][1]=0;
      }
      l++;
    }
    if(r&1){
      r--;
      if(tree[r][0]<=k){
        tree[r][0]=tree[r][1]=0;
      }
    }
    l/=2;
    r/=2;
  }
}

ll query(ll l,ll r,ll k){
  ll ans=0;
  l+=n;
  r+=n;

  while(l<r){
    if(l&1){
      if(tree[l][0]>k){
        ans+=tree[l][1];
      }
      l++;
    }
    if(r&1){
      r--;
      if(tree[r][0]>k){
        ans+=tree[r][1];
      }
    }
    l/=2;
    r/=2;
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>q;

  ll mv=0;
  fr(i,0,n){
    cin>>a[i];
    mv=max(mv,a[i]);
  }

  sieve(mv);

  build();

  ll l,r,k;
  struct Query qr[q];
  fr(i,0,q){
    cin>>l>>r>>k;
    qr[i].l=l;
    qr[i].r=r;
    qr[i].k=k;
    qr[i].id=i;
  }

  sort(qr,qr+1,cmp);

  qr[0].ans=query(qr[0].l-1,qr[0].r,qr[0].k);
  fr(i,1,q){
    update(qr[i].l-1,qr[i].r,qr[i].k);
    qr[i].ans=query(qr[i].l-1,qr[i].r,qr[i].k);
  }

  sort(qr,qr+1,cmp2);

  fr(i,0,q) cout<<qr[i].ans<<"\n";

  return 0;
}
