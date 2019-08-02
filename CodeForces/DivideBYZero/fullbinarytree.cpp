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

ll mx,shift[61];

ll GETLEVEL(ll x){
  return (64-(__builtin_clzll(x)));
}

void SHIFT(ll lev,ll k){
  mx=(1ll<<(lev-1));
  k=k%mx;
  shift[lev]+=k;
  if(shift[lev]>=mx) shift[lev]-=mx;
  if(shift[lev]<=-mx) shift[lev]+=mx;
}

ll GETNODE(ll lev,ll org){
  ll x,m,prv,cur;

  x=org;
  m=(1ll<<(lev-1));
  prv=x-m;
  cur=(((prv+(-1ll*shift[lev]))%m)+m)%m;
  x=m+cur;

  return x;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll q;
  cin>>q;

  ll t,x,k,lev,s,m,par,prv,cur,org;

  fr(i,0,61) shift[i]=0;

  fr(i,0,q){
    cin>>t;

    if(t==1){
      cin>>x>>k;
      lev=GETLEVEL(x);
      SHIFT(lev,k);
    }

    else if(t==2){
      cin>>x>>k;
      lev=GETLEVEL(x);
      m=0;
      fr(i,lev,61){
        s=(1ll<<m)*k;
        SHIFT(i,s);
        m++;
      }
    }

    else{
      cin>>x;
      lev=GETLEVEL(x);
      cout<<x<<" ";
      m=(1ll<<(lev-1));
      prv=x-m;
      cur=(((prv+shift[lev])%m)+m)%m;
      x=m+cur;
      x/=2;
      org=x;
      lev--;
      while(lev>0){
        cout<<GETNODE(lev,org)<<" ";
        org/=2;
        lev--;
      }
      cout<<"\n";
    }
  }

  return 0;
}
